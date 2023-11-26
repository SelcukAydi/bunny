#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <string>
#include <unordered_map>
#include <boost/serialization/unordered_map.hpp>
#include <UnorderedMap.hpp>

namespace boosttest
{
    struct PlainClass
    {
        std::string m_name;
        std::unordered_map<int, std::string> m_map;

        template <typename Archive>
        void serialize(Archive &arc, unsigned int)
        {
            arc & m_name;
            arc & m_map;
        }
    };

    struct ComplexTestClass
    {
        unsigned int m_id{};
        int m_count{};
        std::string m_name;
        std::unordered_map<int, std::unordered_map<int, int>> m_int_map;
        std::unordered_map<int, std::unordered_map<int, PlainClass>> m_plain_map[3];

        template <typename Archive>
        void serialize(Archive &arc, unsigned int)
        {
            arc & m_id;
            arc & m_name;
            arc & m_count;
            arc & m_int_map;
            arc & m_plain_map;
        }
    };
}

namespace bunnytest
{
    using bunny::FieldTag;

    struct PlainClass
    {
        std::string m_name;
        std::unordered_map<int, std::string> m_map;

        template <typename Paper>
        void serialize(Paper &paper)
        {
            paper(m_name, FieldTag{1});
            paper(m_map, FieldTag{2});
        }

        template <typename Paper>
        void deserialize(Paper &paper)
        {
            paper(m_name, FieldTag{1});
            paper(m_map, FieldTag{2});
        }
    };

    struct ComplexTestClass
    {
        unsigned int m_id{};
        int m_count{};
        std::string m_name;
        std::unordered_map<int, std::unordered_map<int, int>> m_int_map;
        std::unordered_map<int, std::unordered_map<int, PlainClass>> m_plain_map[3];

        template <typename Paper>
        void serialize(Paper &paper)
        {
            paper(m_id, FieldTag{1});
            paper(m_name, FieldTag{2});
            paper(m_count, FieldTag{3});
            paper(m_int_map, FieldTag{4});
            paper(m_plain_map, FieldTag{5});
        }

        template <typename Paper>
        void deserialize(Paper &paper)
        {
            paper(m_id, FieldTag{1});
            paper(m_name, FieldTag{2});
            paper(m_count, FieldTag{3});
            paper(m_int_map, FieldTag{4});
            paper(m_plain_map, FieldTag{5});
        }
    };

}