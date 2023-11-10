#pragma once

#include <string>
#include "FieldTag.hpp"

namespace bunny::detail
{
    class EnumComposer
    {
        constexpr EnumComposer() = default;

        protected:
        template <typename Paper, typename T>
        void compose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
        }
    };
}