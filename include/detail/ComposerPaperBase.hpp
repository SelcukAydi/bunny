#pragma once

#include "GlobalCompose.hpp"
#include <ostream>

namespace bunny::detail
{
    class ComposerPaperBase
    {

    public:
        using Stream = std::ostream;

        Stream &m_stream;

        explicit constexpr ComposerPaperBase(Stream &stream) : m_stream(stream)
        {
            m_stream << "bunny";
        }

        Stream &stream() noexcept
        {
            return m_stream;
        }

        template <typename T>
        void compose(const T& data, std::string &key, int id)
        {
            GlobalCompose<T, typename ImplementationLevel<std::remove_reference_t<T>>::type>::invoke(*this, data, key, id);
        }

        template <typename T>
        void composePrimitive(const T& data, std::string &key, int id)
        {
        }

        template <typename T>
        void composeObject(const T& data, std::string &key, int id)
        {
        }

        template <typename T>
        void composeArray(const T& data, std::string &key, int id)
        {
        }

        template <typename T>
        void composePointer(const T& data, std::string &key, int id)
        {
        }

        template <typename T>
        void composeEnum(const T& data, std::string &key, int id)
        {
        }
    };
}