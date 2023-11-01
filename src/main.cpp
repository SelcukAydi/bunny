#include "detail/out_paper.hpp"
#include <sstream>
#include "detail/InPaper.hpp"
#include "detail/InternalTypeInfo.hpp"
#include "detail/ArrayWrapper.hpp"
#include <cassert>

using namespace bunny::detail;

struct SOParams
{
    unsigned int m_lsc_hash{};
    std::string m_param_name{ "mode" };
    int m_arr[3];

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "SOParams::serialize called\n";
        paper.save(m_lsc_hash, key, 1);
        paper.save(m_param_name, key, 2222);
        paper.save(m_arr, key, 5);
    }

    template<typename Paper>
    void deserialize(Paper& paper, std::string key = "", std::size_t index = 0)
    {
        std::cout << "SOParams::deserialize called\n";
        paper.load(m_lsc_hash, key, 1, index);
        paper.load(m_param_name, key, 2222, index);
        paper.load(m_arr, key, 5, index);
    }
};

struct StateData
{
    int m_id{};
    SOParams m_params{};
    SOParams m_param_list[5];
    std::unordered_map<int, SOParams> m_map;

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "StateData::serialize called\n";
        paper.save(m_id, key, 1);
        paper.save(m_params, key, 2);
        paper.save(m_param_list, key, 3);
        paper.save(m_map, key, 4);
    }

    template<typename Paper>
    void deserialize(Paper& paper, std::string key = "", std::size_t index = 0)
    {
        std::cout << "StateData::derialize called\n";
        paper.load(m_id, key, 1, index);
        paper.load(m_params, key, 2, index);
        paper.load(m_param_list, key, 3, index);
        paper.load(m_map, key, 4, index);
    }
};

int main()
{
    std::stringstream ss;
    OutPaper opaper{ ss };
    StateData state_data{};
    state_data.m_id = 909090;
    
    state_data.m_param_list[0].m_lsc_hash = 120;
    state_data.m_param_list[0].m_param_name = "role";
    state_data.m_param_list[0].m_arr[0] = 120;
    
    SOParams params{};
    params.m_lsc_hash = 100;
    params.m_param_name = "myrole";
    state_data.m_map.insert({1,params});

    state_data.m_param_list[4].m_lsc_hash = 139;
    state_data.m_param_list[4].m_param_name = "banner";
    state_data.m_param_list[4].m_arr[2] = 139;


    state_data.serialize(opaper);

    std::cout << ss.str() << '\n';

    InPaper ipaper{ ss };
    StateData state_data1{};
    state_data1.m_id = 454353;
    state_data1.deserialize(ipaper);

    assert(state_data1.m_param_list[0].m_lsc_hash == 120);
    assert(state_data1.m_param_list[0].m_param_name == "role");
    assert(state_data1.m_param_list[0].m_arr[0] == 120);

    assert(state_data1.m_param_list[4].m_lsc_hash == 139);
    assert(state_data1.m_param_list[4].m_param_name == "banner");
    assert(state_data1.m_param_list[4].m_arr[2] == 139);

    return 0;
}
