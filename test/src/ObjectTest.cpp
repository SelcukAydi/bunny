// #include "ObjectTest.hpp"
// #include <gtest/gtest.h>
// #include "detail/out_paper.hpp"
// #include "detail/InPaper.hpp"

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
//     bunny::detail::OutPaper opaper{ss};

//     out_obj.serialize(opaper);

//     bunny::detail::InPaper ipaper{ss};
//     Person in_obj;
//     in_obj.deserialize(ipaper);

//     EXPECT_EQ(out_obj, in_obj);
// }