#pragma once

#include <iostream>

#include "level_impl.hpp"
#include "ArrayWrapper.hpp"

namespace bunny::detail
{
    class OutSerializer
    {
        public:
        template<typename Paper, typename T>
        void saveObjectData(Paper& paper, T& data)
        {
            std::cout << "OutSerializer::saveObjectData called\n";
            (static_cast<std::remove_const_t<T>>(data)).serialize(paper);
        }

        template<typename T>
        void savePointerData(T& ptr, std::ostream& stream)
        {
            std::cout << "OutSerializer::saveObjectData called\n";
        }

        void savePrimitiveData(const std::string& data, std::ostream& stream)
        {
            std::cout << "OutSerializer::savePrimitiveData for string called\n";
        }

        void savePrimitiveData(const int& data, std::ostream& stream)
        {
            std::cout << "OutSerializer::savePrimitiveData for int called\n";
        }

        void savePrimitiveData(const unsigned int& data, std::ostream& stream)
        {
            std::cout << "OutSerializer::savePrimitiveData for unsigned int called\n";
        }
    };

    template <typename T, typename U = std::integral_constant<SerializationLevel, SerializationLevel::kDoNotSerialize>>
    struct GlobalSave;

    template <typename T>
    struct GlobalSave<T, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string& key, int id)
        {
            paper.savePrimitiveData(data, key, id);
        }
    };

    template <typename T>
    struct GlobalSave<T, std::integral_constant<SerializationLevel, SerializationLevel::kArray>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper& paper, Data& data, std::string& key, int id)
        {
            using ActualType = std::remove_all_extents_t<Data>;
            ArrayWrapper<ActualType> data_array(std::addressof(data[0]), std::extent_v<Data>);
            paper.saveArrayData(data_array, key, id);
        }
    };

    template <typename T>
    struct GlobalSave<T, std::integral_constant<SerializationLevel, SerializationLevel::kObject>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string& key, int id)
        {
            paper.saveObjectData(data, key, id);
        }
    };

    template <typename T>
    struct GlobalSave<T, std::integral_constant<SerializationLevel, SerializationLevel::kPointer>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string& key, int id)
        {
            paper.savePointerData(data, key, id);
        }
    };
}