#include "ListTest.hpp"
#include "List.hpp"
#include <gtest/gtest.h>

TEST(ListTest, Simple)
{
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    ListTestPerson person1;
    ListTestPerson person2;
    ListTestPerson person3;

    person1.m_id = 100;
    person1.m_name = "sia";

    person2.m_id = 200;
    person2.m_name = "kia";

    person3.m_id = 300;
    person3.m_name = "pia";

    ListTestManager out_obj;
    out_obj.m_person_list.push_back(person1);
    out_obj.m_person_list.push_back(person2);
    out_obj.m_person_list.push_back(person3);

    out_obj.m_person_list_raw_pointer.push_back(&person1);
    out_obj.m_person_list_raw_pointer.push_back(&person2);
    out_obj.m_person_list_raw_pointer.push_back(&person3);

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    ListTestManager in_obj;
    decomposer >> in_obj;

    EXPECT_EQ(out_obj, in_obj);
}