#pragma once

#include <iostream>

#include "level_impl.hpp"
#include "ArrayWrapper.hpp"

namespace bunny::detail
{
    class InSerializer
    {
    public:
        template<typename Paper, typename T>
        void loadObjectData(Paper& paper, T& data)
        {
            std::cout << "InSerializer::loadObjectData called\n";
            (static_cast<std::remove_const_t<T>>(data)).serialize(paper);
        }

        template<typename T>
        void loadPointerData(T& ptr, std::ostream& stream)
        {
            std::cout << "InSerializer::loadPointerData called\n";
        }

        void loadPrimitiveData(const std::string& data, std::ostream& stream)
        {
            std::cout << "InSerializer::loadPrimitiveData for string called\n";
        }

        void loadPrimitiveData(const int& data, std::ostream& stream)
        {
            std::cout << "InSerializer::loadPrimitiveData for int called\n";
        }

        void loadPrimitiveData(const unsigned int& data, std::ostream& stream)
        {
            std::cout << "InSerializer::loadPrimitiveData for unsigned int called\n";
        }
    };

    template <typename T, typename U = std::integral_constant<SerializationLevel, SerializationLevel::kDoNotSerialize>>
    struct GlobalLoad;

    template <typename T>
    struct GlobalLoad<T, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper& paper, Data& data, std::string& key, int id)
        {
            paper.loadPrimitiveData(data, key, id);
        }
    };

    template <typename T>
    struct GlobalLoad<T, std::integral_constant<SerializationLevel, SerializationLevel::kArray>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper& paper, Data& data, std::string& key, int id)
        {
            ArrayWrapper<Data> data_array(*data, std::extent_v<Data>);
            paper.loadArrayData(data_array, key, id);
        }
    };

    template <typename T>
    struct GlobalLoad<T, std::integral_constant<SerializationLevel, SerializationLevel::kObject>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper& paper, Data& data, std::string& key, int id)
        {
            paper.loadObjectData(data, key, id);
        }
    };

    template <typename T>
    struct GlobalLoad<T, std::integral_constant<SerializationLevel, SerializationLevel::kPointer>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper& paper, Data& data, std::string& key, int id)
        {
            paper.loadPointerData(data, key, id);
        }
    };
}