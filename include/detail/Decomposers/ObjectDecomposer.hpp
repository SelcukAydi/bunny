#pragma once

#include "detail/TypeTraits.hpp"
#include "detail/FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class ObjectDecomposer
    {
        constexpr ObjectDecomposer() = default;

    public:
        template <typename Paper, typename T>
        static void decompose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
            if constexpr (TypeHasDeserializeMethod<std::remove_cv_t<T>, std::remove_cv_t<Paper>>::value)
            {
                (static_cast<std::remove_const_t<T>&>(data)).deserialize(paper, key);
            }
            else
            {
                deserialize(paper, const_cast<std::remove_const_t<T>&>(data), key);
            }
        }
    };
}