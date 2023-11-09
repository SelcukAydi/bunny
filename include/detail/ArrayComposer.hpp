#pragma once

#include "ArrayWrapper.hpp"
#include <string>

namespace bunny::detail
{
    class ArrayComposer
    {
        constexpr ArrayComposer() = default;

        protected:
        template <typename Paper, typename T>
        void compose(Paper &paper, ArrayWrapper<T> &data, std::string key, int id)
        {
        }
    };
}