#pragma once

#include "../FieldTag.hpp"
#include <sstream>
#include <string>
#include <iostream>

namespace bunny::detail
{
    class PrimitiveDecomposer
    {
        constexpr PrimitiveDecomposer() = default;

    public:
        template <typename Paper>
        static void decompose(Paper &paper, char &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, signed char &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, unsigned char &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, unsigned short int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, signed short int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, signed int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, unsigned int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, long unsigned int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, long signed int &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }

        template <typename Paper>
        static void decompose(Paper &paper, std::string &data, std::string key, FieldTag ftag, std::string& input_data)
        {
            std::istringstream input_stream{input_data};

            input_stream.get();
            input_stream.get();
            input_stream >> data;

            if (input_stream.fail())
            {
                std::cerr << "Input stream error: Could not load integer data!\n";
                return;
            }
        }
    };
}