#include "ComposerPaper.hpp"
#include <sstream>
#include <gtest/gtest.h>

struct MockTestPerson
{
    int m_id{};

    template<typename Paper>
    void serialize(Paper &paper, std::string key = "")
    {
        paper(m_id, key, 1);
    }
};

TEST(MockTest, Simple)
{
    std::stringstream ss;
    bunny::ComposerPaper composer_paper{ss};
    
    MockTestPerson person1{};
    composer_paper << person1;
}