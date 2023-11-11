#include "ComposerPaper.hpp"
#include "UnorderedMap.hpp"
#include "SharedPointer.hpp"
#include "DecomposerPaper.hpp"
#include <sstream>
#include <gtest/gtest.h>

using bunny::detail::FieldTag;

struct MockTestPerson
{
    int m_id{};
    int m_arr[3];

    template<typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        // paper(m_id, key, FieldTag{10});
        paper(m_arr, key, FieldTag{20});
    }

    template<typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        // paper(m_id, key, FieldTag{10});
        paper(m_arr, key, FieldTag{20});
    }
};

struct MockTestManager
{
    int m_score{99};
    MockTestPerson m_person;
    std::unordered_map<int, int> m_map;
    std::unordered_map<int, MockTestPerson> m_map1;
    std::unordered_map<std::string, MockTestPerson> m_map2;
    std::shared_ptr<MockTestPerson> m_person_ptr{};
    std::string m_name{"selcuk"};

    template <typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_person, key, FieldTag{1});
        // paper(m_score, key, FieldTag{2});
        // paper(m_map, key, FieldTag{3});
        // paper(m_map1, key, FieldTag{4});
        // paper(m_map2, key, FieldTag{5});
        // paper(m_person_ptr, key, FieldTag{6});
        // paper(m_name, key, FieldTag{7});
    }

    template <typename Paper>
    void deserialize(Paper &paper, std::string key = "")
    {
        paper(m_person, key, FieldTag{1});
        // paper(m_score, key, FieldTag{2});
        // paper(m_map, key, FieldTag{3});
        // paper(m_map1, key, FieldTag{4});
        // paper(m_map2, key, FieldTag{5});
        // paper(m_person_ptr, key, FieldTag{6});
        // paper(m_name, key, FieldTag{7});
    }
};

TEST(MockTest, Simple)
{
    std::stringstream ss;
    bunny::ComposerPaper composer_paper{ss};

    MockTestPerson person1{};
    
    person1.m_arr[0] = 200;
    person1.m_arr[1] = 201;
    person1.m_arr[2] = 202;

    MockTestManager manager1{};
    manager1.m_person = person1;
    manager1.m_map.insert({1, 100});
    manager1.m_map.insert({2, 200});
    manager1.m_map1.insert({900, person1});
    manager1.m_map2.insert({"sia", person1});
    manager1.m_person_ptr = std::make_shared<MockTestPerson>(person1);

    composer_paper << manager1;
    std::cout << ss.str() << '\n';

    MockTestManager in_obj{};
    bunny::DecomposerPaper decomposer_paper{ss};
    decomposer_paper >> in_obj;

    std::cout << "done\n";
}