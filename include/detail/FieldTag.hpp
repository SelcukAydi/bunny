#pragma once

namespace bunny
{
    struct FieldTag
    {
        constexpr FieldTag() : m_is_valid(false) {}
        explicit constexpr FieldTag(int value) : m_value(value), m_is_valid(true) {}

        constexpr bool valid() const noexcept
        {
            return m_is_valid;
        }

        constexpr int value() const noexcept
        {
            return m_value;
        }
        
        private:
        int m_value{};
        bool m_is_valid{};
    };
}