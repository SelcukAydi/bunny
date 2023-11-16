#pragma once

#include <string>
#include <unordered_map>
#include <boost/serialization/unordered_map.hpp>

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