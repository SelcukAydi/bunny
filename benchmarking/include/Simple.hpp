#pragma once

#include <string>
#include <boost/serialization/vector.hpp>
#include "Vector.hpp"

namespace boosttest
{
    struct Role
    {
        std::string m_roleName{};

        template<typename Archive>
        void serialize(Archive& arc, const unsigned int)
        {
            arc & m_roleName;
        }
    };

    struct Person
    {
        std::string m_name{};
        int m_id{};
        std::vector<Role> m_roles{};

        template<typename Archive>
        void serialize(Archive& arc, const unsigned int)
        {
            arc & m_name;
            arc & m_id;
            arc & m_roles;
        }
    };
}

namespace bunnytest
{
    using bunny::FieldTag;

    struct Role
    {
        std::string m_roleName{};

        template<typename Paper>
        void serialize(Paper& paper)
        {
            paper(m_roleName, FieldTag{1});
        }

        template<typename Paper>
        void deserialize(Paper& paper)
        {
            paper(m_roleName, FieldTag{1});
        }
    };

    struct Person
    {
        std::string m_name{};
        int m_id{};
        std::vector<Role> m_roles{};

        template<typename Paper>
        void serialize(Paper& paper)
        {
            paper(m_name, FieldTag{1});
            paper(m_id, FieldTag{2});
            paper(m_roles, FieldTag{3});
        }

        template<typename Paper>
        void deserialize(Paper& paper)
        {
            paper(m_name, FieldTag{1});
            paper(m_id, FieldTag{2});
            paper(m_roles, FieldTag{3});
        }
    };
}