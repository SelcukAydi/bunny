#pragma once

#include "detail/GlobalCompose.hpp"
#include <vector>
#include <iostream>
#include <sstream>

namespace bunny::detail
{
    template <typename Paper, typename T>
    void serialize_impl(Paper &paper, const std::vector<T> &data, std::string key = "")
    {
        paper.stream() << "\n";
        paper.stream() << key << " " << data.size();

        for (std::size_t i = 0; i < data.size(); ++i)
        {
            std::string tmp_key{key};
            tmp_key.append(".item.").append(std::to_string(i));
            paper(data[i], tmp_key, FieldTag{});
        }
    }

    template <typename Paper, typename T>
    void deserialize_impl(Paper &paper, std::vector<T> &data, std::string key = "")
    {
        auto& parsed_data = paper.parsedData();
        auto itr = parsed_data.find(key);

        if (itr == parsed_data.end())
        {
            std::cerr << "Could not find the key: " << key << '\n';
            return;
        }

        std::istringstream input_stream{itr->second};

        std::size_t size;
        input_stream >> size;

        for (std::size_t i = 0; i < size; ++i)
        {
            std::string tmp_key{key};
            tmp_key.append(".item.").append(std::to_string(i));
            T obj;
            paper(obj, tmp_key, FieldTag{});
            data.push_back(obj);
        }
    }
}

namespace bunny
{
    template <typename Paper, typename T>
    void serialize(Paper &paper, const std::vector<T> &data, std::string key = "")
    {
        detail::serialize_impl(paper, data, key);
    }

    template <typename Paper, typename T>
    void deserialize(Paper &paper, std::vector<T> &data, std::string key = "")
    {
        detail::deserialize_impl(paper, data, key);
    }
}