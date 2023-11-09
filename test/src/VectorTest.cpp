// #include "VectorTest.hpp"
// #include "detail/out_paper.hpp"
// #include "detail/InPaper.hpp"
// #include <gtest/gtest.h>

// TEST(VectorTest, Simple)
// {
//     auto person1 = std::make_shared<VectorPersonClass>();
//     auto person2 = std::make_shared<VectorPersonClass>();

//     person1->m_id = 100;
//     person2->m_id = 101;

//     VectorTestSimpleClass out_obj;
//     out_obj.m_person_list.push_back(person1);
//     out_obj.m_person_list.push_back(person2);

//     std::stringstream ss;
//     bunny::detail::OutPaper opaper{ss};

//     out_obj.serialize(opaper);

//     std::cout << ss.str() << '\n';

//     VectorTestSimpleClass in_obj;
//     bunny::detail::InPaper ipaper{ss};

//     in_obj.deserialize(ipaper);

//     EXPECT_TRUE(out_obj.m_person_list.size() == in_obj.m_person_list.size());
// }

// TEST(VectorTest, Cascade)
// {
//     VectorTestCascadeClass out_obj;

//     std::vector<int> v1{1,2,3,4,5,6};
//     std::vector<int> v2{10,11,12,13,14};

//     out_obj.m_vector.push_back(v1);
//     out_obj.m_vector.push_back(v2);

//     std::stringstream ss;
//     bunny::detail::OutPaper opaper{ss};

//     out_obj.serialize(opaper);

//     std::cout << ss.str() << '\n';

//     VectorTestCascadeClass in_obj;
//     bunny::detail::InPaper ipaper{ss};

//     in_obj.deserialize(ipaper);

//     EXPECT_TRUE(out_obj.m_vector.size() == in_obj.m_vector.size());
// }