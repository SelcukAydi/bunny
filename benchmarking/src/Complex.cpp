#include "Complex.hpp"
#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include "Complex.pb.h"
#include <benchmark/benchmark.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>

void PerformanceTestBoostComplex(std::size_t);
void PerformanceTestBunnyComplex(std::size_t);
void PerformanceTestProtoComplex(std::size_t);

static void BM_BoostComplex(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestBoostComplex(count++);
    }
}

static void BM_BunnyComplex(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestBunnyComplex(count++);
    }
}

static void BM_ProtoComplex(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestProtoComplex(count++);
    }
}

BENCHMARK(BM_BoostComplex);
BENCHMARK(BM_BunnyComplex);
BENCHMARK(BM_ProtoComplex);

// BENCHMARK_MAIN();

constexpr std::uint64_t kCountThreshold = 100000;

void PerformanceTestBoostComplex(std::size_t count)
{
    using boosttest::ComplexTestClass;
    using boosttest::PlainClass;

    std::stringstream ss;
    boost::archive::text_oarchive oa{ss};

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

    oa << out_obj;

    if (count % kCountThreshold == 0)
    {
        boost::archive::text_iarchive ia{ss};
        ComplexTestClass in_obj;
        ia >> in_obj;
    }
}

void PerformanceTestBunnyComplex(std::size_t count)
{
    using bunnytest::ComplexTestClass;
    using bunnytest::PlainClass;

    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

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

    composer << out_obj;

    if (count % kCountThreshold == 0)
    {
        bunny::DecomposerPaper decomposer{ss};
        ComplexTestClass in_obj;
        decomposer >> in_obj;
    }
}

void PerformanceTestProtoComplex(std::size_t count)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    std::stringstream ss{};

    {
        complexbenchmarking::ComplexClass out_obj;
        out_obj.set_name("sia");
        out_obj.set_count(99999);
        out_obj.set_id(909090);

        complexbenchmarking::ComplexClass_PlainClass plain_class1;
        auto plain1_map = plain_class1.mutable_my_map();
        plain_class1.set_name("plain1");
        plain1_map->insert({1, "left"});
        plain1_map->insert({2, "right"});
        plain1_map->insert({3, "forward"});
        plain1_map->insert({4, "backward"});

        complexbenchmarking::ComplexClass_PlainClass plain_class2;
        auto plain2_map = plain_class2.mutable_my_map();
        plain_class2.set_name("plain2");
        plain2_map->insert({1, "left10"});
        plain2_map->insert({2, "right20"});
        plain2_map->insert({3, "forward30"});
        plain2_map->insert({4, "backward40"});

        complexbenchmarking::ComplexClass_PlainClass plain_class3;
        auto plain3_map = plain_class3.mutable_my_map();
        plain_class3.set_name("plain3");
        plain3_map->insert({1, "left"});
        plain3_map->insert({2, "right"});
        plain3_map->insert({3, "forward"});
        plain3_map->insert({4, "backward"});

        complexbenchmarking::ComplexClass_PlainClass plain_class4;
        auto plain4_map = plain_class4.mutable_my_map();
        plain_class4.set_name("plain4");
        plain4_map->insert({1, "left10"});
        plain4_map->insert({2, "right20"});
        plain4_map->insert({3, "forward30"});
        plain4_map->insert({4, "backward40"});

        complexbenchmarking::ComplexClass_InnerPlainClassMapArray map_array1;
        map_array1.mutable_my_maps()->mutable_my_map()->insert({100, plain_class1});
        map_array1.mutable_my_maps()->mutable_my_map()->insert({200, plain_class2});

        complexbenchmarking::ComplexClass_InnerPlainClassMapArray map_array2;
        map_array2.mutable_my_maps()->mutable_my_map()->insert({100, plain_class3});
        map_array2.mutable_my_maps()->mutable_my_map()->insert({200, plain_class4});

        out_obj.mutable_plain_class_map()->Add(std::move(map_array1));
        out_obj.mutable_plain_class_map()->Add(std::move(map_array2));

        complexbenchmarking::ComplexClass_InnerIntMap int_map1;
        int_map1.mutable_m_map()->insert({1, 10});

        complexbenchmarking::ComplexClass_InnerIntMap int_map2;
        int_map2.mutable_m_map()->insert({2, 20});

        out_obj.mutable_int_map()->insert({7979, int_map1});
        out_obj.mutable_int_map()->insert({9090, int_map2});

        out_obj.SerializeToOstream(&ss);
    }

    if (count % kCountThreshold == 0)
    {
        complexbenchmarking::ComplexClass in_obj;
        in_obj.ParseFromIstream(&ss);
    }
}