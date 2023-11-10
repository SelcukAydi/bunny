#pragma once

#include "detail/GlobalCompose.hpp"
#include <unordered_map>

namespace bunny::detail
{
    template <typename Paper, typename Key, typename Val>
    void serialize_impl(Paper &paper, const std::unordered_map<Key, Val> &data, std::string key = "")
    {
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
}

namespace bunny
{
    template <typename Paper, typename Key, typename Val>
    void serialize(Paper &paper, const std::unordered_map<Key, Val> &data, std::string key = "")
    {
        detail::serialize_impl(paper, data, key);
    }
}