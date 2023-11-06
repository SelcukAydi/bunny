#include "ArrayTest.hpp"

#include <gtest/gtest.h>
#include "detail/out_paper.hpp"
#include "detail/InPaper.hpp"


TEST(ArrayTest, Simple)
{
    SimpleTestClass out_obj;
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    out_obj.m_arr[0] = 100;
    out_obj.m_arr[1] = 101;
    out_obj.m_arr[2] = 102;
    out_obj.m_arr[3] = 103;
    out_obj.m_arr[4] = 104;

    out_obj.serialize(opaper);

    bunny::detail::InPaper ipaper{ss};
    SimpleTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(in_obj == out_obj);
}

TEST(ArrayTest, IgnoredKey)
{
    KeyIgnoreTestClass out_obj;
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    out_obj.m_arr[0] = 100;
    out_obj.m_arr[1] = 101;
    out_obj.m_arr[2] = 102;
    out_obj.m_arr[3] = 103;
    out_obj.m_arr[4] = 104;

    out_obj.serialize(opaper);

    bunny::detail::InPaper ipaper{ss};
    KeyIgnoreTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_FALSE(in_obj == out_obj);
}

TEST(ArrayTest, CascadeArrayTest)
{
    CascadeArrayTestClass out_obj;
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    SimpleTestClass test1;
    test1.m_arr[0] = 100;
    test1.m_arr[1] = 101;
    test1.m_arr[2] = 102;
    test1.m_arr[3] = 103;
    test1.m_arr[4] = 104;

    SimpleTestClass test2;
    test2.m_arr[0] = 900;
    test2.m_arr[1] = 901;
    test2.m_arr[2] = 902;
    test2.m_arr[3] = 903;
    test2.m_arr[4] = 904;

    out_obj.m_class_list[0] = test1;
    out_obj.m_class_list[9] = test2;

    out_obj.serialize(opaper);

    bunny::detail::InPaper ipaper{ss};
    CascadeArrayTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(in_obj == out_obj);
}

TEST(ArrayTest, SimpleStringTest)
{
    SimpleStringTestClass out_obj;
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    out_obj.m_arr[0] = "a";
    out_obj.m_arr[0] = "b";
    out_obj.m_arr[0] = "c";
    out_obj.m_arr[0] = "d";
    out_obj.m_arr[0] = "e";

    out_obj.serialize(opaper);

    bunny::detail::InPaper ipaper{ss};
    SimpleStringTestClass in_obj;
    in_obj.deserialize(ipaper);

    EXPECT_TRUE(in_obj == out_obj);
}