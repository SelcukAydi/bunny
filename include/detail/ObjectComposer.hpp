#pragma once

#include <string>

namespace bunny::detail
{
    class ObjectComposer
    {
        constexpr ObjectComposer() = default;

        protected:
        template <typename Paper, typename T>
        void compose(Paper &paper, T &data, std::string key, int id)
        {
        }
    };
}