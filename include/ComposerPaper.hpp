#pragma once

#include "detail/FieldTag.hpp"
#include "detail/TypeTraits.hpp"
#include "detail/ComposerPaperBase.hpp"

namespace bunny
{
    class ComposerPaper : public detail::ComposerPaperBase<ComposerPaper>
    {
    public:
        constexpr ComposerPaper(Stream &stream) : ComposerPaperBase(stream)
        {
        }

        // We can declare this as a friend function.
        //
        template <typename T>
        void operator()(const T &data, std::string &key, detail::FieldTag ftag)
        {
            compose(data, key, ftag);
        }

        template <typename T>
        friend Stream &operator<<(Stream &stream, T &data);
    };

    template <typename T>
    ComposerPaper &operator<<(ComposerPaper &paper, const T &data)
    {
        if constexpr (detail::TypeHasSerializeMethod<std::remove_cv_t<T>, std::remove_cv_t<ComposerPaper>>::value)
        {
            (static_cast<std::remove_const_t<T>>(data)).serialize(paper);
        }
        else
        {
            serialize(paper, data);
        }

        return paper;
    }
}