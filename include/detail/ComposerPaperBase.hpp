#pragma once

#include "GlobalCompose.hpp"
#include "PrimitiveComposer.hpp"
#include "ObjectComposer.hpp"
#include "ArrayComposer.hpp"
#include "PointerComposer.hpp"
#include "FieldTag.hpp"
#include <ostream>

namespace bunny::detail
{
    template <typename Derived>
    class ComposerPaperBase
    {
    public:
        using Stream = std::ostream;

        Stream &m_stream;

        explicit constexpr ComposerPaperBase(Stream &stream) : m_stream(stream)
        {
        }

        Stream &stream() noexcept
        {
            return m_stream;
        }

        Derived &This()
        {
            return static_cast<Derived &>(*this);
        }

        template <typename T>
        void compose(const T &data, std::string &key, FieldTag ftag)
        {
            GlobalCompose<T, typename ImplementationLevel<std::remove_reference_t<T>>::type>::invoke(this->This(), data, key, ftag);
        }

        template <typename T>
        void composePrimitive(const T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            PrimitiveComposer::compose(this->This(), data, key, ftag);
        }

        template <typename T>
        void composeObject(const T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            ObjectComposer::compose(this->This(), data, key, ftag);
        }

        template <typename T>
        void composeArray(const ArrayWrapper<T> &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            ArrayComposer::compose(this->This(), data, key, ftag);
        }

        template <typename T>
        void composePointer(const T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            PointerComposer::compose(this->This(), data, key, ftag);
        }

        template <typename T>
        void composeEnum(const T &data, std::string key, FieldTag ftag)
        {
        }
    };
}