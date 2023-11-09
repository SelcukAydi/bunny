#pragma once

#include <string>

namespace bunny::detail
{
    class PrimitiveComposer
    {
        constexpr PrimitiveComposer() = default;
        
        protected:
        template <typename Paper>
        void compose(Paper &paper, char &data, std::string key, int id)
        {
            key.append(".");
            key.append(std::to_string(id));

            paper.stream() << "\n";
            paper.stream() << key << " " << data;
        }

        template <typename Paper>
        void compose(Paper &paper, signed char &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, unsigned char &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, unsigned short int &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, signed short int &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, signed int &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, unsigned int &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, long unsigned int &data, std::string key, int id)
        {
        }

        template <typename Paper>
        void compose(Paper &paper, long signed int &data, std::string key, int id)
        {
        }
    };
}