#pragma once

#include <string>
#include <unordered_map>

struct PlainClass
{
    std::string m_name;
    std::unordered_map<int, std::string> m_map;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_name, key, 1);
        paper.save(m_map, key, 2);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_name, key, 1, index);
        paper.load(m_map, key, 2, index);
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
        paper.save(m_id, key, 1);
        paper.save(m_name, key, 2);
        paper.save(m_count, key, 3);
        paper.save(m_int_map, key, 4);
        paper.save(m_plain_map, key, 5);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_id, key, 1, index);
        paper.load(m_name, key, 2, index);
        paper.load(m_count, key, 3, index);
        paper.load(m_int_map, key, 4, index);
        paper.load(m_plain_map, key, 5, index);
    }
};