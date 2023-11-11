#pragma once

#include "detail/ArrayWrapper.hpp"
#include "detail/FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class ArrayDecomposer
    {
    public:
        constexpr ArrayDecomposer() = default;

        template <typename Paper, typename T>
        static void decompose(Paper &paper, ArrayWrapper<T> &data, std::string key, FieldTag ftag)
        {
            key.append(".a");

            auto &parsed_data = paper.parsedData();

            auto itr = parsed_data.find(key);

            if (itr == parsed_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{itr->second};
            std::size_t size;
            input_stream >> size;

            auto ptr = data.address();

            for (std::size_t i = 0; i < size; ++i)
            {
                std::string tmp_key{key};
                tmp_key.append(".item.").append(std::to_string(i));
                paper(*(ptr + i), tmp_key, FieldTag{});
            }
        }
    };
}