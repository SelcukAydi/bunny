#pragma once

#include "detail/GlobalCompose.hpp"
#include <memory>

namespace bunny::detail
{
    template <typename Paper, typename T>
    void serialize_impl(Paper &paper, const std::shared_ptr<T> &data, std::string key = "")
    {
        if (data.get() == nullptr)
        {
            paper.stream() << "\n";
            paper.stream() << key << " "
                           << "invalid";
            return;
        }

        paper.stream() << "\n";
        paper.stream() << key << " "
                       << "valid";

        paper(*data, key, FieldTag{});
    }

    template <typename Paper, typename T>
    void deserialize_impl(Paper &paper, std::shared_ptr<T> &data, std::string key = "")
    {
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
            data.reset();
            return;
        }

        T *obj = new T{};
        paper(*obj, key, FieldTag{});
        data.reset(obj);
    }
}

namespace bunny
{
    template <typename Paper, typename T>
    void serialize(Paper &paper, const std::shared_ptr<T> &data, std::string key = "")
    {
        detail::serialize_impl(paper, data, key);
    }

    template <typename Paper, typename T>
    void deserialize(Paper &paper, std::shared_ptr<T> &data, std::string key = "")
    {
        detail::deserialize_impl(paper, data, key);
    }
}