#include "detail/out_paper.hpp"
#include <sstream>

using namespace bunny::detail;

struct SOParams
{
    unsigned int m_lsc_hash{};
    std::string m_param_name{"mode"};

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "SOParams::serialize called\n";
        paper.save(m_lsc_hash, key, 1);
        paper.save(m_param_name, key, 2222);
    }
};

struct StateData
{
    int m_id{};
    SOParams m_params{};

    template<typename Paper>
    void serialize(Paper& paper, std::string key = "")
    {
        std::cout << "StateData::serialize called\n";
        paper.save(m_id, key, 1);
        paper.save(m_params, key, 2);
    }
};

int main()
{   
    std::stringstream ss;
    OutPaper opaper{ss};
    StateData state_data{};
    state_data.serialize(opaper);

    std::cout << ss.str() << '\n';

    return 0;
}
