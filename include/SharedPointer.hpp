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
}

namespace bunny
{
    template <typename Paper, typename T>
    void serialize(Paper &paper, const std::shared_ptr<T> &data, std::string key = "")
    {
        detail::serialize_impl(paper, data, key);
    }
}