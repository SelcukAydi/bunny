#include "SharedPtrTest.hpp"
#include "detail/InPaper.hpp"
#include "detail/out_paper.hpp"

#include <memory>
#include <gtest/gtest.h>

TEST(SharedptrTest, Simple)
{
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    SharedPtrSimpleTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    auto ptr = std::make_shared<SharedPtrPersonTestClass>();
    ptr->m_number = 200;

    out_obj.m_person = ptr;

    out_obj.serialize(opaper);

    std::cout << ss.str() << '\n';

    bunny::detail::InPaper ipaper{ss};
    SharedPtrSimpleTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(out_obj.m_person->m_number == in_obj.m_person->m_number);
}

TEST(SharedptrTest, Nullptr)
{
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    SharedPtrSimpleTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    out_obj.serialize(opaper);

    std::cout << ss.str() << '\n';

    bunny::detail::InPaper ipaper{ss};
    SharedPtrSimpleTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(in_obj.m_person.get() == nullptr);
}

TEST(SharedptrTest, Complex1)
{
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    SharedPtrComplexTestClass out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";

    auto person2 = std::make_shared<SharedPtrPersonTestClass>();
    person2->m_number = 200;

    out_obj.m_person1 = nullptr;
    out_obj.m_person2 = std::make_shared<std::shared_ptr<SharedPtrPersonTestClass>>(person2);

    out_obj.serialize(opaper);

    std::cout << ss.str() << '\n';

    bunny::detail::InPaper ipaper{ss};
    SharedPtrComplexTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(in_obj.m_person1.get() == nullptr);
    EXPECT_TRUE(in_obj.m_person2.get()->get()->m_number == out_obj.m_person2.get()->get()->m_number);
}