#pragma once

#include "detail/FieldTag.hpp"
#include "detail/TypeTraits.hpp"
#include "detail/Composers/ComposerPaperBase.hpp"

namespace bunny
{
    class ComposerPaper : public detail::ComposerPaperBase<ComposerPaper>
    {
    public:
        constexpr ComposerPaper(Stream &stream) : ComposerPaperBase(stream)
        {
        }

        // This overload is for clients of this library.
        //
        template <typename T>
        void operator()(const T &data, FieldTag ftag)
        {
            std::string tmp{getCurrentKey()};
            compose(data, getCurrentKey(), ftag);
            setCurrentKey(tmp);
        }

        // We can declare this as a friend function.
        //
        template <typename T>
        void operator()(const T &data, std::string &key, FieldTag ftag)
        {
            compose(data, key, ftag);
        }

        template <typename T>
        friend Stream &operator<<(Stream &stream, T &data);
    };

    template <typename T>
    ComposerPaper &operator<<(ComposerPaper &paper, const T &data)
    {
        // TODO: this tag must start with a new line.
        //
        paper.stream() << "bunny";

        if constexpr (detail::TypeHasSerializeMethod<std::remove_cv_t<T>, std::remove_cv_t<ComposerPaper>>::value)
        {
            (const_cast<std::remove_const_t<T> &>(data)).serialize(paper);
        }
        else
        {
            serialize(paper, data);
        }

        return paper;
    }
}