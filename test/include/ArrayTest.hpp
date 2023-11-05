#pragma once

#include <string>

struct SimpleTestClass
{
    int m_arr[5]{1, 2, 3, 4, 5};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_arr, key, 9090);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_arr, key, 9090, index);
    }

    bool operator==(const SimpleTestClass &other) const &
    {
        bool ans = true;
        for (std::size_t i = 0; i < std::size(m_arr); ++i)
        {
            if (m_arr[i] != other.m_arr[i])
            {
                ans = false;
                break;
            }
        }

        return ans;
    }

    friend bool operator!=(const SimpleTestClass &first, const SimpleTestClass &second);
};

bool operator!=(const SimpleTestClass &first, const SimpleTestClass &second)
{
    return !(first == second);
}

struct KeyIgnoreTestClass
{
    int m_arr[5]{1, 2, 3, 4, 5};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_arr, key, 9090);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_arr, key, 1231, index);
    }

    bool operator==(const KeyIgnoreTestClass &other) const &
    {
        bool ans = true;
        for (std::size_t i = 0; i < std::size(m_arr); ++i)
        {
            if (m_arr[i] != other.m_arr[i])
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};

struct CascadeArrayTestClass
{
    SimpleTestClass m_class_list[10];

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_class_list, key, 9090);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_class_list, key, 9090, index);
    }

    bool operator==(const CascadeArrayTestClass &other) const &
    {
        bool ans = true;
        for (std::size_t i = 0; i < std::size(m_class_list); ++i)
        {
            if (m_class_list[i] != other.m_class_list[i])
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};

struct SimpleStringTestClass
{
    std::string m_arr[5];

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper.save(m_arr, key, 9090);
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "", std::size_t index = 0)
    {
        paper.load(m_arr, key, 9090, index);
    }

    bool operator==(const SimpleStringTestClass &other) const &
    {
        bool ans = true;
        for (std::size_t i = 0; i < std::size(m_arr); ++i)
        {
            if (m_arr[i] != other.m_arr[i])
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};