#pragma once

#include "detail/ComposerPaperBase.hpp"

namespace bunny
{
    class ComposerPaper : public detail::ComposerPaperBase
    {
    public:
        constexpr ComposerPaper(Stream &stream) : ComposerPaperBase(stream)
        {
        }

        // We can declare this as a friend function.
        //
        template <typename T>
        void operator()(const T &data, std::string &key, int id)
        {
            compose(data, key, id);
        }

        template <typename T>
        friend Stream &operator<<(Stream &stream, T &data);
    };

    template <typename T>
    ComposerPaper &operator<<(ComposerPaper &paper, const T &data)
    {
        (static_cast<T>(data)).serialize(paper);
        return paper;
    }
}