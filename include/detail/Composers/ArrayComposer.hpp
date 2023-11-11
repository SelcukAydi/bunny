#pragma once

#include "detail/ArrayWrapper.hpp"
#include "detail/FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class ArrayComposer
    {
        constexpr ArrayComposer() = default;

    public:
        template <typename Paper, typename T>
        static void compose(Paper &paper, const ArrayWrapper<T> &data, std::string key, FieldTag ftag)
        {
            key.append(".a");

            paper.stream() << "\n";
            paper.stream() << key << " " << data.count();

            std::size_t count = 0;
            T *ptr = data.address();

            while (count < data.count())
            {
                std::string tmp_key{key};
                tmp_key.append(".item.").append(std::to_string(count));
                paper(*(ptr + count++), tmp_key, FieldTag{});
            }
        }
    };
}