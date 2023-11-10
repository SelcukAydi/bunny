#pragma once

#include "level_impl.hpp"
#include "ArrayWrapper.hpp"
#include "FieldTag.hpp"

namespace bunny::detail
{
    template <typename T, typename U = std::integral_constant<SerializationLevel, SerializationLevel::kDoNotSerialize>>
    struct GlobalCompose;

    template <typename T>
    struct GlobalCompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.composePrimitive(data, key, ftag);
        }
    };

    template <typename T>
    struct GlobalCompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kArray>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            using ActualType = std::remove_all_extents_t<Data>;
            ArrayWrapper<ActualType> data_array(std::addressof(data[0]), std::extent_v<Data>);
            paper.composeArray(data_array, key, ftag);
        }
    };

    template <typename T>
    struct GlobalCompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kObject>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.composeObject(data, key, ftag);
        }
    };

    template <typename T>
    struct GlobalCompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kPointer>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.composePointer(data, key, ftag);
        }
    };
}