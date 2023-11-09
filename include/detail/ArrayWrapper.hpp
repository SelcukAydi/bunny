#pragma once

#include <type_traits>

namespace bunny::detail
{
    template<typename T>
    class ArrayWrapper
    {
        using PointerType = T*;
        using ThisType = std::remove_pointer_t<T>;

    public:
        constexpr explicit ArrayWrapper(PointerType const ptr, std::size_t const num_of_elements) : m_ptr(ptr),
            m_element_count(num_of_elements) {}
        
        constexpr std::size_t count() const&
        {
            return m_element_count;
        }

        constexpr PointerType address() const&
        {
            return m_ptr;
        }

        template<typename Paper>
        void serialize(Paper& paper, std::string key = "")
        {
            auto count = 0;
            while(count < m_element_count)
            {
                // std::cout << "key:" << key << "serialize item " << count++ << '\n';
            }
        }

        template<typename Paper>
        void deserialize(Paper& paper, std::string key = "")
        {
            auto count = 0;
            while(count < m_element_count)
            {
                paper.load(*(m_ptr + count++));
            }
        }

    private:
        PointerType const m_ptr;
        std::size_t const m_element_count;
    };
}