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
    void serialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
        paper(m_department, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
        paper(m_department, FieldTag{2});
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
    void serialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
        paper(m_name, FieldTag{2});
        paper(m_manager, FieldTag{3});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
        paper(m_name, FieldTag{2});
        paper(m_manager, FieldTag{3});
    }

    bool operator==(const Person& other) const&
    {
        return (m_id == other.m_id) && (m_name == other.m_name) && (m_manager == other.m_manager);
    }
};