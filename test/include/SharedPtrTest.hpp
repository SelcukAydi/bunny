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
    void serialize(Paper &paper)
    {
        paper(m_number, FieldTag{1});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_number, FieldTag{1});
    }
};

struct SharedPtrSimpleTestClass
{
    std::string m_name;
    int m_id;
    std::shared_ptr<SharedPtrPersonTestClass> m_person{nullptr};

    template <typename Paper>
    void serialize(Paper &paper)
    {
        paper(m_name, FieldTag{1});
        paper(m_id, FieldTag{2});
        paper(m_person, FieldTag{3});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_name, FieldTag{1});
        paper(m_id, FieldTag{2});
        paper(m_person, FieldTag{3});
    }
};

struct SharedPtrComplexTestClass
{
    std::string m_name;
    int m_id;
    std::shared_ptr<SharedPtrPersonTestClass> m_person1{nullptr};
    std::shared_ptr<std::shared_ptr<SharedPtrPersonTestClass>> m_person2{nullptr};
    std::shared_ptr<int*> m_int_ptr{nullptr};

    template <typename Paper>
    void serialize(Paper &paper)
    {
        paper(m_name, FieldTag{1});
        paper(m_id, FieldTag{2});
        paper(m_person1, FieldTag{3});
        paper(m_person2, FieldTag{4});
        paper(m_int_ptr, FieldTag{5});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_name, FieldTag{1});
        paper(m_id, FieldTag{2});
        paper(m_person1, FieldTag{30});
        paper(m_person2, FieldTag{4});
        paper(m_int_ptr, FieldTag{5});
    }
};