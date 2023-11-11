#pragma once

#include <string>
#include "detail/TypeTraits.hpp"

namespace bunny::detail
{
    class ObjectComposer
    {
        constexpr ObjectComposer() = default;

    public:
        template <typename Paper, typename T>
        static void compose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
            if constexpr (TypeHasSerializeMethod<std::remove_cv_t<T>, std::remove_cv_t<Paper>>::value)
            {
                (const_cast<std::remove_const_t<T>&>(data)).serialize(paper, key);
            }
            else
            {
                serialize(paper, data, key);
            }
        }
    };
}