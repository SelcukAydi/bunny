#include "ComplexClassTest.hpp"
#include "detail/InPaper.hpp"
#include "detail/out_paper.hpp"
#include <gtest/gtest.h>

TEST(ComplexTest, Complex1)
{
    std::stringstream ss;
    bunny::detail::OutPaper opaper{ss};

    ComplexTestClass out_obj;
    
    PlainClass plain1;
    plain1.m_name = "plain1";
    plain1.m_map.insert({1, "left"});
    plain1.m_map.insert({2, "right"});
    plain1.m_map.insert({3, "forward"});
    plain1.m_map.insert({4, "backward"});

    PlainClass plain2;
    plain2.m_name = "plain2";
    plain2.m_map.insert({10, "left10"});
    plain2.m_map.insert({20, "right20"});
    plain2.m_map.insert({30, "forward30"});
    plain2.m_map.insert({40, "backward40"});

    std::unordered_map<int, PlainClass> map1;
    map1.insert({100, plain1});
    map1.insert({200, plain2});

    PlainClass plain3;
    plain3.m_name = "plain3";
    plain3.m_map.insert({11, "left"});
    plain3.m_map.insert({21, "right"});
    plain3.m_map.insert({31, "forward"});
    plain3.m_map.insert({41, "backward"});

    PlainClass plain4;
    plain4.m_name = "plain4";
    plain4.m_map.insert({105, "left10"});
    plain4.m_map.insert({205, "right20"});
    plain4.m_map.insert({305, "forward30"});
    plain4.m_map.insert({405, "backward40"});

    std::unordered_map<int, PlainClass> map2;
    map2.insert({100, plain3});
    map2.insert({200, plain4});

    // This scheme causes a problem. We need to add a testcase
    // for arrays with zero full one empty second full.
    // POTANTIAL FIX: Arrays and continuous containers
    // will have in sequence keys per item.
    //
    out_obj.m_plain_map[0].insert({888, map1});
    out_obj.m_plain_map[2].insert({999, map2});

    out_obj.m_count = 7070;
    out_obj.m_id = 2323;
    
    std::unordered_map<int, int> map_int1;
    map_int1.insert({1, 10});

    std::unordered_map<int, int> map_int2;
    map_int2.insert({2, 20});

    out_obj.m_int_map.insert({7979, map_int1});
    out_obj.m_int_map.insert({9090, map_int2});

    out_obj.serialize(opaper);
    std::cout << ss.str() << '\n';

    bunny::detail::InPaper ipaper{ss};
    ComplexTestClass in_obj;
    in_obj.deserialize(ipaper);

    std::cout << "Finished\n";

}