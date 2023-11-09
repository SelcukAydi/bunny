#pragma once

#include <type_traits>
#include "level_enum.hpp"
#include <string>

namespace bunny::detail
{
    template <typename T>
    struct ImplementationLevel
    {
        template <typename U>
        friend class ImplementationLevel;

        constexpr ImplementationLevel() = default;

        using type = std::conditional_t<std::is_fundamental_v<T>, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>,
            std::conditional_t<std::is_array_v<T>, std::integral_constant<SerializationLevel, SerializationLevel::kArray>,
            std::conditional_t<std::is_enum_v<T>, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>,
            std::conditional_t<std::is_class_v<T>, std::integral_constant<SerializationLevel, SerializationLevel::kObject>,
            std::conditional_t<std::is_pointer_v<T>, std::integral_constant<SerializationLevel, SerializationLevel::kPointer>,
            std::integral_constant<SerializationLevel, SerializationLevel::kDoNotSerialize>>>>>>;

        static constexpr auto value = static_cast<std::underlying_type_t<SerializationLevel>>(type::value);

        template <typename U>
        constexpr bool operator==(const ImplementationLevel<U>& other) noexcept
        {
            return this->value == other.value;
        }
    };

    template<>
    struct ImplementationLevel<std::string>
    {
        using type = std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>;
    };

    template <SerializationLevel level, typename T>
    using IsImplLevelSame = std::is_same<typename ImplementationLevel<T>::type, std::integral_constant<SerializationLevel, level>>;
}