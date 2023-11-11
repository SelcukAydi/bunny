#pragma once

#include "detail/TypeTraits.hpp"
#include "detail/FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class PointerComposer
    {
        constexpr PointerComposer() = default;

    public:
        template <typename Paper, typename T>
        static void compose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
            using ObjectType = std::remove_pointer_t<T>;

            if (data == nullptr)
            {
                paper.stream() << "\n";
                paper.stream() << key << " "
                               << "invalid";
                return;
            }
            else
            {
                paper.stream() << "\n";
                paper.stream() << key << " "
                               << "valid";
            }

            if constexpr (TypeHasSerializeMethod<std::remove_cv_t<ObjectType>, std::remove_cv_t<Paper>>::value)
            {
                (const_cast<std::remove_const_t<ObjectType> &>(*data)).serialize(paper, key);
            }
            else
            {
                serialize(paper, *data, key);
            }
        }
    };
}