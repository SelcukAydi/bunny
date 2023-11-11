#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <string>
#include <unordered_map>

using bunny::FieldTag;

struct PlainClass
{
    std::string m_name;
    std::unordered_map<int, std::string> m_map;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_map, key, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_map, key, FieldTag{2});
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
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_count, key, FieldTag{3});
        paper(m_int_map, key, FieldTag{4});
        paper(m_plain_map, key, FieldTag{5});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_count, key, FieldTag{3});
        paper(m_int_map, key, FieldTag{4});
        paper(m_plain_map, key, FieldTag{5});
    }
};