#include "SharedPtrTest.hpp"
#include "SharedPointer.hpp"

#include <memory>
#include <gtest/gtest.h>

TEST(SharedptrTest1, Simple)
{
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    SharedPtrSimpleTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    auto ptr = std::make_shared<SharedPtrPersonTestClass>();
    ptr->m_number = 200;

    out_obj.m_person = ptr;

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    SharedPtrSimpleTestClass in_obj;
    decomposer >> in_obj;

    EXPECT_TRUE(out_obj.m_person->m_number == in_obj.m_person->m_number);
}

TEST(SharedptrTest1, Nullptr)
{
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    SharedPtrSimpleTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    SharedPtrSimpleTestClass in_obj;
    decomposer >> in_obj;

    EXPECT_TRUE(in_obj.m_person.get() == nullptr);
}

TEST(SharedptrTest1, Complex1)
{
    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    SharedPtrComplexTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    auto person2 = std::make_shared<SharedPtrPersonTestClass>();
    person2->m_number = 200;

    out_obj.m_person1 = nullptr;
    out_obj.m_person2 = std::make_shared<std::shared_ptr<SharedPtrPersonTestClass>>(person2);
    out_obj.m_int_ptr = std::make_shared<int*>(new int(123));

    composer << out_obj;

    bunny::DecomposerPaper decomposer{ss};
    SharedPtrComplexTestClass in_obj;
    decomposer >> in_obj;

    EXPECT_TRUE(in_obj.m_person1.get() == nullptr);
    EXPECT_TRUE(in_obj.m_person2.get()->get()->m_number == out_obj.m_person2.get()->get()->m_number);
}