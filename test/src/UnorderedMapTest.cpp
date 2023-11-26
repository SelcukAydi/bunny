#include "UnorderedMapTest.hpp"
#include "UnorderedMap.hpp"
#include <gtest/gtest.h>

TEST(UnorderedMapTest, Simple)
{
    SimpleUnorderedTestClass out_obj;
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    out_obj.m_map.insert({1, "sia"});
    out_obj.m_map.insert({2, "john"});
    out_obj.m_map.insert({3, "alis"});

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    SimpleUnorderedTestClass in_obj;
    decomposer >> in_obj;

    EXPECT_EQ(out_obj, in_obj);
}

TEST(UnorderedMapTest, Cascaded)
{
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    SimpleUnorderedTestClass obj1;
    obj1.m_map.insert({1, "sia"});
    obj1.m_map.insert({2, "john"});
    obj1.m_map.insert({3, "alis"});

    SimpleUnorderedTestClass obj2;
    obj2.m_map.insert({4, "he"});
    obj2.m_map.insert({5, "she"});
    obj2.m_map.insert({6, "we"});

    CascadedUnorderedTestClass out_obj;
    out_obj.m_map.insert({650, obj1});
    out_obj.m_map.insert({700, obj2});

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    CascadedUnorderedTestClass in_obj;
    decomposer >> in_obj;

    EXPECT_EQ(out_obj, in_obj);
}