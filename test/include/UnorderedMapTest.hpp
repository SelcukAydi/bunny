#pragma once

#include <unordered_map>
#include <string>

struct SimpleUnorderedTestClass
{
    std::unordered_map<int, std::string> m_map;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_map, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_map, key, 1, index);
    }

    bool operator==(const SimpleUnorderedTestClass& other) const&
    {
        bool ans = true;
        for(auto itr = m_map.begin(); itr != m_map.end(); ++itr)
        {
            auto itr_other = other.m_map.find(itr->first);
            if(itr_other == other.m_map.end())
            {
                ans = false;
                break;
            }

            if(itr->second != itr_other->second)
            {
                ans = false;
                break;
            }
        }

        return ans;
    }

    friend bool operator!=(const SimpleUnorderedTestClass& first, const SimpleUnorderedTestClass& second);
};

bool operator!=(const SimpleUnorderedTestClass& first, const SimpleUnorderedTestClass& second)
{
    return !(first == second);
}

struct CascadedUnorderedTestClass
{
    std::unordered_map<int, SimpleUnorderedTestClass> m_map;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_map, key, 1);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_map, key, 1, index);
    }

    bool operator==(const CascadedUnorderedTestClass& other) const&
    {
        bool ans = true;
        for(auto itr = m_map.begin(); itr != m_map.end(); ++itr)
        {
            auto itr_other = other.m_map.find(itr->first);
            if(itr_other == other.m_map.end())
            {
                ans = false;
                break;
            }

            if(itr->second != itr_other->second)
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};