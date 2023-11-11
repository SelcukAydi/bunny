#pragma once

#include "detail/level_impl.hpp"
#include "detail/ArrayWrapper.hpp"
#include "detail/FieldTag.hpp"

namespace bunny::detail
{
    template <typename T, typename U = std::integral_constant<SerializationLevel, SerializationLevel::kDoNotSerialize>>
    struct GlobalDecompose;

    template <typename T>
    struct GlobalDecompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kPrimitive>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.decomposePrimitive(data, key, ftag);
        }
    };

    template <typename T>
    struct GlobalDecompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kArray>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            using ActualType = std::remove_all_extents_t<Data>;
            ArrayWrapper<ActualType> data_array(std::addressof(data[0]), std::extent_v<Data>);
            paper.decomposeArray(data_array, key, ftag);
        }
    };

    template <typename T>
    struct GlobalDecompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kObject>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.decomposeObject(data, key, ftag);
        }
    };

    template <typename T>
    struct GlobalDecompose<T, std::integral_constant<SerializationLevel, SerializationLevel::kPointer>>
    {
        template <typename Paper, typename Data>
        static constexpr void invoke(Paper &paper, Data &data, std::string &key, FieldTag ftag)
        {
            paper.decomposePointer(data, key, ftag);
        }
    };
}