#pragma once

#include <string>
#include <memory>

struct SharedPtrPersonTestClass
{
    int m_number;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_number, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_number, key, 1, index);
    }
};

struct SharedPtrSimpleTestClass
{
    std::string m_name;
    int m_id;
    std::shared_ptr<SharedPtrPersonTestClass> m_person{nullptr};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_name, key, 1);
        paper.save(m_id, key, 2);
        paper.save(m_person, key, 3);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_name, key, 1, index);
        paper.load(m_id, key, 2, index);
        paper.load(m_person, key, 3, index);
    }
};