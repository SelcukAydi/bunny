#pragma once

#include "../FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class PointerDecomposer
    {
        constexpr PointerDecomposer() = default;

        protected:
        template <typename Paper, typename T>
        void decompose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
        }
    };
}