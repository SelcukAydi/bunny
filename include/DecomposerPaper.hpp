#pragma once

#include "detail/FieldTag.hpp"
#include "detail/TypeTraits.hpp"
#include "detail/Decomposers/DecomposerPaperBase.hpp"

namespace bunny
{
    class DecomposerPaper : public detail::DecomposerPaperBase<DecomposerPaper>
    {
    public:
        constexpr DecomposerPaper(Stream &stream) : DecomposerPaperBase(stream)
        {
        }

        // This overload is for clients of this library.
        //
        template <typename T>
        void operator()(T &data, FieldTag ftag)
        {
            std::string tmp{getCurrentKey()};
            decompose(data, getCurrentKey(), ftag);
            setCurrentKey(tmp);
        }

        // We can declare this as a friend function.
        //
        template <typename T>
        void operator()(T &data, std::string &key, FieldTag ftag)
        {
            decompose(data, key, ftag);
        }

        template <typename T>
        friend Stream &operator>>(Stream &stream, T &data);
    };

    template <typename T>
    DecomposerPaper &operator>>(DecomposerPaper &paper, T &data)
    {
        std::string input_key;
        paper.stream() >> input_key;

        if (input_key != "bunny")
        {
            std::cerr << "InputStreamError: Stream is not a bunny buffer!\n";
        }

        paper.parse();

        if constexpr (detail::TypeHasDeserializeMethod<std::remove_cv_t<T>, std::remove_cv_t<DecomposerPaper>>::value)
        {
            (static_cast<std::remove_const_t<T>&>(data)).deserialize(paper);
        }
        else
        {
            deserialize(paper, data);
        }

        return paper;
    }
}