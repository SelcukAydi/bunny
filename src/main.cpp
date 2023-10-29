#include "detail/out_paper.hpp"
#include <sstream>
#include "detail/InPaper.hpp"
#include "detail/InternalTypeInfo.hpp"
#include "detail/ArrayWrapper.hpp"

using namespace bunny::detail;

struct SOParams
{
    unsigned int m_lsc_hash{};
    std::string m_param_name{ "mode" };

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "SOParams::serialize called\n";
        paper.save(m_lsc_hash, key, 1);
        paper.save(m_param_name, key, 2222);
    }

    template<typename Paper>
    void deserialize(Paper& paper, std::string key = "")
    {
        std::cout << "SOParams::deserialize called\n";
        paper.load(m_lsc_hash, key, 1);
        paper.load(m_param_name, key, 2222);
    }
};

struct StateData
{
    int m_id{};
    SOParams m_params{};
    int arr[20];

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "StateData::serialize called\n";
        paper.save(m_id, key, 1);
        paper.save(m_params, key, 2);
        paper.save(arr, key, 3);
    }

    template<typename Paper>
    void deserialize(Paper& paper, std::string key = "")
    {
        std::cout << "StateData::derialize called\n";
        paper.load(m_id, key, 1);
        paper.load(m_params, key, 2);
    }
};

int main()
{
    std::stringstream ss;
    OutPaper opaper{ ss };
    StateData state_data{};
    state_data.m_id = 909090;
    state_data.serialize(opaper);

    std::cout << ss.str() << '\n';

    InPaper ipaper{ ss };
    StateData state_data1{};
    state_data1.m_id = 454353;
    state_data1.deserialize(ipaper);

    return 0;
}
