#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <string>
#include <memory>

using bunny::FieldTag;

struct SharedPtrPersonTestClass
{
    int m_number;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_number, key, FieldTag{1});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_number, key, FieldTag{1});
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
        paper(m_name, key, FieldTag{1});
        paper(m_id, key, FieldTag{2});
        paper(m_person, key, FieldTag{3});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_id, key, FieldTag{2});
        paper(m_person, key, FieldTag{3});
    }
};

struct SharedPtrComplexTestClass
{
    std::string m_name;
    int m_id;
    std::shared_ptr<SharedPtrPersonTestClass> m_person1{nullptr};
    std::shared_ptr<std::shared_ptr<SharedPtrPersonTestClass>> m_person2{nullptr};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_id, key, FieldTag{2});
        paper(m_person1, key, FieldTag{3});
        paper(m_person2, key, FieldTag{4});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_name, key, FieldTag{1});
        paper(m_id, key, FieldTag{2});
        paper(m_person1, key, FieldTag{30});
        paper(m_person2, key, FieldTag{4});
    }
};