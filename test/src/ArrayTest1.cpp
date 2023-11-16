// #include "ArrayTest1.hpp"
// #include <gtest/gtest.h>


// TEST(ArrayTest1, Simple)
// {
//     SimpleTestClass out_obj;
//     std::stringstream ss;
//     bunny::ComposerPaper composer{ss};

//     out_obj.m_arr[0] = 100;
//     out_obj.m_arr[1] = 101;
//     out_obj.m_arr[2] = 102;
//     out_obj.m_arr[3] = 103;
//     out_obj.m_arr[4] = 104;

//     composer << out_obj;

//     bunny::DecomposerPaper decomposer{ss};
//     SimpleTestClass in_obj;
//     decomposer >> in_obj;

//     EXPECT_TRUE(in_obj == out_obj);
// }

// TEST(ArrayTest1, IgnoredKey)
// {
//     KeyIgnoreTestClass out_obj;
//     std::stringstream ss;
//     bunny::ComposerPaper composer{ss};

//     out_obj.m_arr[0] = 100;
//     out_obj.m_arr[1] = 101;
//     out_obj.m_arr[2] = 102;
//     out_obj.m_arr[3] = 103;
//     out_obj.m_arr[4] = 104;

//     composer << out_obj;

//     bunny::DecomposerPaper decomposer{ss};
//     KeyIgnoreTestClass in_obj;
//     decomposer >> in_obj;

//     EXPECT_FALSE(in_obj == out_obj);
// }

// TEST(ArrayTest1, CascadeArrayTest)
// {
//     CascadeArrayTestClass out_obj;
//     std::stringstream ss;
//     bunny::ComposerPaper composer{ss};

//     SimpleTestClass test1;
//     test1.m_arr[0] = 100;
//     test1.m_arr[1] = 101;
//     test1.m_arr[2] = 102;
//     test1.m_arr[3] = 103;
//     test1.m_arr[4] = 104;

//     SimpleTestClass test2;
//     test2.m_arr[0] = 900;
//     test2.m_arr[1] = 901;
//     test2.m_arr[2] = 902;
//     test2.m_arr[3] = 903;
//     test2.m_arr[4] = 904;

//     out_obj.m_class_list[0] = test1;
//     out_obj.m_class_list[9] = test2;

//     composer << out_obj;

//     bunny::DecomposerPaper decomposer{ss};
//     CascadeArrayTestClass in_obj;
//     decomposer >> in_obj;

//     EXPECT_TRUE(in_obj == out_obj);
// }

// TEST(ArrayTest1, SimpleStringTest)
// {
//     SimpleStringTestClass out_obj;
//     std::stringstream ss;
//     bunny::ComposerPaper composer{ss};

//     out_obj.m_arr[0] = "a";
//     out_obj.m_arr[0] = "b";
//     out_obj.m_arr[0] = "c";
//     out_obj.m_arr[0] = "d";
//     out_obj.m_arr[0] = "e";

//     composer << out_obj;

//     bunny::DecomposerPaper decomposer{ss};
//     SimpleStringTestClass in_obj;
//     decomposer >> in_obj;

//     EXPECT_TRUE(in_obj == out_obj);
// }