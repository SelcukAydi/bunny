#pragma once

#include <string>

namespace bunny::detail
{
    class PointerComposer
    {
        constexpr PointerComposer() = default;

        protected:
        template <typename Paper, typename T>
        void compose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
        }
    };
}