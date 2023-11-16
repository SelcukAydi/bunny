#pragma once

#include "detail/Composers/GlobalCompose.hpp"
#include <unordered_map>
#include <iostream>
#include <sstream>

namespace bunny::detail
{
    template <typename Paper, typename Key, typename Val>
    void serialize_impl(Paper &paper, const std::unordered_map<Key, Val> &data)
    {
        std::string key = paper.getCurrentKey();
        key.append(".um");

        paper.stream() << "\n";
        paper.stream() << key << " " << data.size();

        std::size_t count = 0;

        for (auto itr = data.begin(); itr != data.end(); ++itr)
        {
            std::string tmp_key{key};
            tmp_key.append(".key.").append(std::to_string(count));

            std::string tmp_val{key};
            tmp_val.append(".val.").append(std::to_string(count));
            ++count;

            paper(itr->first, tmp_key, FieldTag{});
            paper(itr->second, tmp_val, FieldTag{});
        }
    }

    template <typename Paper, typename Key, typename Val>
    void deserialize_impl(Paper &paper, std::unordered_map<Key, Val> &data)
    {
        std::string key = paper.getCurrentKey();
        key.append(".um");

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
            Key entry_key{};
            Val entry_data{};

            std::string tmp_key{key};
            tmp_key.append(".key.").append(std::to_string(i));

            std::string tmp_val{key};
            tmp_val.append(".val.").append(std::to_string(i));

            paper(entry_key, tmp_key, FieldTag{});
            paper(entry_data, tmp_val, FieldTag{});

            data[entry_key] = entry_data;
        }
    }
}

namespace bunny
{
    template <typename Paper, typename Key, typename Val>
    void serialize(Paper &paper, const std::unordered_map<Key, Val> &data)
    {
        detail::serialize_impl(paper, data);
    }

    template <typename Paper, typename Key, typename Val>
    void deserialize(Paper &paper, std::unordered_map<Key, Val> &data)
    {
        detail::deserialize_impl(paper, data);
    }
}