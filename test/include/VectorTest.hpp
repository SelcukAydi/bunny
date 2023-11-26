#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <memory>
#include <vector>
#include <string>

using bunny::FieldTag;

struct VectorPersonClass
{
    int m_id{};

    template <typename Paper>
    void serialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_id, FieldTag{1});
    }
};

struct VectorTestSimpleClass
{
    std::vector<std::shared_ptr<VectorPersonClass>> m_person_list;

    template <typename Paper>
    void serialize(Paper &paper)
    {
        paper(m_person_list, FieldTag{1});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_person_list, FieldTag{1});
    }
};

struct VectorTestCascadeClass
{
    std::vector<std::vector<int>> m_vector;

    template <typename Paper>
    void serialize(Paper &paper)
    {
        paper(m_vector, FieldTag{1});
    }

    template <typename Paper>
    void deserialize(Paper &paper)
    {
        paper(m_vector, FieldTag{1});
    }
};