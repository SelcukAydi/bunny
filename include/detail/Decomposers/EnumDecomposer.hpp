#pragma once

#include <string>
#include ".detail/FieldTag.hpp"

namespace bunny::detail
{
    class EnumDecomposer
    {
        constexpr EnumDecomposer() = default;

        protected:
        template <typename Paper, typename T>
        void decompose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
        }
    };
}