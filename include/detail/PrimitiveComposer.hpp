#pragma once

#include <string>
#include "FieldTag.hpp"

namespace bunny::detail
{
    class PrimitiveComposer
    {
        constexpr PrimitiveComposer() = default;

    public:
        template <typename Paper>
        static void compose(Paper &paper, const char &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const signed char &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const unsigned char &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const unsigned short int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const signed short int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const signed int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const unsigned int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const long unsigned int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const long signed int &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        static void compose(Paper &paper, const std::string &data, std::string key, FieldTag ftag)
        {
            paper.stream() << "\n";
            paper.stream() << key << " " << data.size() << " " << data;
        }
    };
}