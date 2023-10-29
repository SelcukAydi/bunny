#pragma once

#include <typeindex>
#include <unordered_map>

namespace bunny::detail
{
    struct InternalTypeInfo
    {
        constexpr InternalTypeInfo(std::type_index& indx) : m_type_index(indx) {}

    private:
        std::type_index m_type_index;
    };


    using InternalTypeInfoMap = std::unordered_map<std::type_index, std::string>;

    struct InternalTypeInfoRegistry
    {
        static inline InternalTypeInfoMap m_types;
    };
}