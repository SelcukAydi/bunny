// #include "ObjectTest1.hpp"
// #include <gtest/gtest.h>

// TEST(ObjectTest, Simple)
// {
//     Person out_obj;
//     Manager manager1;
//     manager1.m_id = 100;
//     manager1.m_department = "science";
//     out_obj.m_manager = manager1;

//     out_obj.m_id = 800;
//     out_obj.m_name = "sia";

//     std::stringstream ss;
//     bunny::ComposerPaper composer{ss};

//     composer << out_obj;

//     bunny::DecomposerPaper decomposer{ss};
//     Person in_obj;
//     decomposer >> in_obj;

//     EXPECT_EQ(out_obj, in_obj);
// }