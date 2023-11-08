#pragma once

#include <memory>
#include <vector>
#include <string>

struct VectorPersonClass
{
    int m_id{};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_id, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_id, key, 1, index);
    }
};

struct VectorTestSimpleClass
{
    std::vector<std::shared_ptr<VectorPersonClass>> m_person_list;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_person_list, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_person_list, key, 1, index);
    }
};

struct VectorTestCascadeClass
{
    std::vector<std::vector<int>> m_vector;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_vector, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_vector, key, 1, index);
    }
};