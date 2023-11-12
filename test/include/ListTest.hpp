#pragma once

#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include <list>

using bunny::FieldTag;

struct ListTestPerson
{
    unsigned int m_id{};
    std::string m_name{};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{1});
        paper(m_name, key, FieldTag{2});
    }

    friend bool operator==(const ListTestPerson &lhs, const ListTestPerson &rhs);
};

bool operator==(const ListTestPerson &lhs, const ListTestPerson &rhs)
{
    if(&lhs == &rhs) return true;
    return (lhs.m_id == rhs.m_id) && (lhs.m_name == rhs.m_name);
}

struct ListTestManager
{
    std::list<ListTestPerson> m_person_list;
    std::list<ListTestPerson*> m_person_list_raw_pointer;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_person_list, key, FieldTag{1});
        paper(m_person_list_raw_pointer, key, FieldTag{2});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_person_list, key, FieldTag{1});
        paper(m_person_list_raw_pointer, key, FieldTag{2});
    }

    friend bool operator==(const ListTestManager &lhs, const ListTestManager &rhs);
};

bool operator==(const ListTestManager &lhs, const ListTestManager &rhs)
{
    if(&lhs == &rhs) return true;
    if(lhs.m_person_list.size() != rhs.m_person_list.size()) return false;
    if(lhs.m_person_list_raw_pointer.size() != rhs.m_person_list_raw_pointer.size()) return false;

    auto itr1 = lhs.m_person_list.cbegin();
    auto itr2 = rhs.m_person_list.cbegin();

    while((itr1 != lhs.m_person_list.cend()))
    {
        if(!(*itr1 == *itr2)) return false;
        ++itr1;
        ++itr2;
    }

    auto itr3 = lhs.m_person_list_raw_pointer.cbegin();
    auto itr4 = rhs.m_person_list_raw_pointer.cbegin();

    while((itr3 != lhs.m_person_list_raw_pointer.cend()))
    {
        if(!(**itr3 == **itr4)) return false;
        ++itr3;
        ++itr4;
    }

    return true;
}