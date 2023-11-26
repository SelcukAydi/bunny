#include "Simple.hpp"
#include "ComposerPaper.hpp"
#include "DecomposerPaper.hpp"
#include "Person.pb.h"
#include <benchmark/benchmark.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>

void PerformanceTestBoostSimple(std::size_t);
void PerformanceTestBunnySimple(std::size_t);
void PerformanceTestProtoSimple(std::size_t);

static void BM_BoostSimple(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestBoostSimple(count++);
    }
}

static void BM_BunnySimple(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestBunnySimple(count++);
    }
}

static void BM_ProtoSimple(benchmark::State &state)
{
    std::size_t count{};
    for (auto _ : state)
    {
        PerformanceTestProtoSimple(count++);
    }
}

BENCHMARK(BM_BoostSimple);
BENCHMARK(BM_BunnySimple);
BENCHMARK(BM_ProtoSimple);

BENCHMARK_MAIN();

constexpr std::uint64_t kCountThreshold = 100;

void PerformanceTestBoostSimple(std::size_t count)
{
    using boosttest::Person;
    using boosttest::Role;

    Role role1;
    role1.m_roleName = "director";

    Role role2;
    role2.m_roleName = "manager";

    Person out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";
    out_obj.m_roles.push_back(role1);
    out_obj.m_roles.push_back(role2);

    std::stringstream ss;
    boost::archive::text_oarchive oa{ss};

    oa << out_obj;

    if (count % kCountThreshold == 0)
    {
        boost::archive::text_iarchive ia{ss};
        Person in_obj;
        ia >> in_obj;
    }
}

void PerformanceTestBunnySimple(std::size_t count)
{
    using bunnytest::Person;
    using bunnytest::Role;

    Role role1;
    role1.m_roleName = "director";

    Role role2;
    role2.m_roleName = "manager";

    Person out_obj;
    out_obj.m_id = 100;
    out_obj.m_name = "sia";
    out_obj.m_roles.push_back(role1);
    out_obj.m_roles.push_back(role2);

    std::stringstream ss;
    bunny::ComposerPaper composer{ss};

    composer << out_obj;

    if (count % kCountThreshold == 0)
    {
        bunny::DecomposerPaper decomposer{ss};
        Person in_obj;
        decomposer >> in_obj;
    }
}

void PerformanceTestProtoSimple(std::size_t count)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    benchmarktesting::Person person1{};
    person1.set_id(100);
    person1.set_name("sia");

    auto role1 = person1.add_roles();
    role1->set_rolename("director");

    auto role2 = person1.add_roles();
    role2->set_rolename("manager");

    std::stringstream ss{};
    person1.SerializeToOstream(&ss);

    if ((count % kCountThreshold == 0))
    {
        benchmarktesting::Person person2{};
        person2.ParseFromIstream(&ss);

        for (std::size_t i = 0; i < person2.roles_size(); ++i)
        {
            auto role = person2.roles(i);
        }
    }
}