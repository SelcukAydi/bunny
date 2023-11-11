#pragma once

#include "detail/FieldTag.hpp"
#include <string>

namespace bunny::detail
{
    class PointerDecomposer
    {
        constexpr PointerDecomposer() = default;

    public:
        template <typename Paper, typename T>
        static void decompose(Paper &paper, T &data, std::string key, FieldTag ftag)
        {
            using ObjectType = std::remove_pointer_t<T>;

            auto &parsed_data = paper.parsedData();

            auto itr = parsed_data.find(key);

            if (itr == parsed_data.end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            std::istringstream input_stream{itr->second};

            std::string is_valid;
            input_stream >> is_valid;

            if (is_valid == "invalid")
            {
                data = nullptr;
                return;
            }

            data = new ObjectType{};
            paper(*data, key, FieldTag{});
        }
    };
}