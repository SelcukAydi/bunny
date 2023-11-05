#pragma once

#include <cstdint>
#include <string>

struct Manager
{
    int m_id;
    std::string m_department;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_id, key, 1);
        paper.save(m_department, key, 2);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_id, key, 1, index);
        paper.load(m_department, key, 2, index);
    }

    bool operator==(const Manager& other) const&
    {
        return (other.m_id == m_id) && (m_department == other.m_department);
    }
};

struct Person
{
    int m_id;
    std::string m_name;
    Manager m_manager;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_id, key, 1);
        paper.save(m_name, key, 2);
        paper.save(m_manager, key, 3);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_id, key, 1, index);
        paper.load(m_name, key, 2, index);
        paper.load(m_manager, key, 3, index);
    }

    bool operator==(const Person& other) const&
    {
        return (m_id == other.m_id) && (m_name == other.m_name) && (m_manager == other.m_manager);
    }
};