#pragma once

#include "GlobalDecompose.hpp"
#include "PrimitiveDecomposer.hpp"
#include "ObjectDecomposer.hpp"
#include "ArrayDecomposer.hpp"
#include "PointerDecomposer.hpp"
#include <istream>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace bunny::detail
{
    template <typename Derived>
    class DecomposerPaperBase
    {
    public:
        using Stream = std::istream;
        using ParsedDataEntry = std::unordered_map<std::string, std::string>;
        using ParsedData = std::vector<ParsedDataEntry>;

    private:
        Stream &m_stream;
        std::size_t m_index{};
        ParsedData m_data;
        std::string m_current_key{};

    public:
        explicit constexpr DecomposerPaperBase(Stream &stream) : m_stream(stream)
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

        ParsedDataEntry& parsedData() noexcept
        {
            return m_data[m_index];
        }

        std::size_t index() const noexcept
        {
            return m_index;
        }

        inline std::string getCurrentKey() const noexcept
        {
            return m_current_key;
        }

        inline std::string setCurrentKey(std::string& key) noexcept
        {
            return m_current_key = key;
        }

        void parse()
        {
            while (!m_stream.eof())
            {
                std::string input_key;
                m_stream >> input_key;

                if (input_key == "bunny")
                {
                    ++m_index;
                    continue;
                }

                if (m_stream.fail())
                {
                    std::cerr << "Input stream error: Could not load key!\n";
                    return;
                }

                std::string input_data;
                m_stream.get();
                std::getline(m_stream, input_data, '\n');

                if (m_stream.fail())
                {
                    std::cerr << "Input stream error: Could not load data with key: " << input_key << '\n';
                    return;
                }

                if (m_data.size() < m_index + 1)
                {
                    m_data.resize((m_index + 1) * 2);
                }

                m_data[m_index].insert({input_key, input_data});
            }
        }

        template <typename T>
        void decompose(T &data, std::string key, FieldTag ftag)
        {
            GlobalDecompose<T, typename ImplementationLevel<std::remove_reference_t<T>>::type>::invoke(this->This(), data, key, ftag);
        }

        template <typename T>
        void decomposePrimitive(T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            auto itr = m_data[m_index].find(key);

            if (itr == m_data[m_index].end())
            {
                std::cerr << "Could not find the key: " << key << '\n';
                return;
            }

            PrimitiveDecomposer::decompose(this->This(), data, key, ftag, itr->second);
        }

        template <typename T>
        void decomposeObject(T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            ObjectDecomposer::decompose(this->This(), data, key, ftag);
        }

        template <typename T>
        void decomposeArray(ArrayWrapper<T> &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            ArrayDecomposer::decompose(this->This(), data, key, ftag);
        }

        template <typename T>
        void decomposePointer(T &data, std::string key, FieldTag ftag)
        {
            if (ftag.valid())
            {
                key.append(".");
                key.append(std::to_string(ftag.value()));
            }

            PointerDecomposer::decompose(this->This(), data, key, ftag);
        }

        template <typename T>
        void decomposeEnum(T &data, std::string key, FieldTag ftag)
        {
        }
    };
}