#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <cstdint>
#include <string>

using bunny::FieldTag;

struct Manager
{
    int m_id;
    std::string m_department;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_department, key, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_department, key, FieldTag{2});
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
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_manager, key, FieldTag{3});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
        paper(m_manager, key, FieldTag{3});
    }

    bool operator==(const Person& other) const&
    {
        return (m_id == other.m_id) && (m_name == other.m_name) && (m_manager == other.m_manager);
    }
};