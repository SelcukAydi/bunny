#include "ComposerPaper.hpp"
#include "UnorderedMap.hpp"
#include <sstream>
#include <gtest/gtest.h>

using bunny::detail::FieldTag;

struct MockTestPerson
{
    int m_id{};

    template<typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, FieldTag{10});
    }
};

struct MockTestManager
{
    int m_score{99};
    MockTestPerson m_person;
    std::unordered_map<int, int> m_map;
    std::unordered_map<int, MockTestPerson> m_map1;
    std::unordered_map<std::string, MockTestPerson> m_map2;

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_person, key, FieldTag{1});
        paper(m_score, key, FieldTag{2});
        paper(m_map, key, FieldTag{3});
        paper(m_map1, key, FieldTag{4});
        paper(m_map2, key, FieldTag{5});
    }
};

TEST(MockTest, Simple)
{
    std::stringstream ss;
    bunny::ComposerPaper composer_paper{ss};

    MockTestPerson person1{};
    MockTestManager manager1{};
    manager1.m_person = person1;
    manager1.m_map.insert({1, 100});
    manager1.m_map.insert({2, 200});
    manager1.m_map1.insert({900, person1});
    manager1.m_map2.insert({"sia", person1});

    composer_paper << manager1;
    composer_paper << manager1;

    std::cout << ss.str() << '\n';
}