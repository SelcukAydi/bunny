#pragma once

#include <type_traits>
#include <string>

namespace bunny::detail
{
    template <typename T, typename PaperT>
    class TypeHasSerializeMethod
    {
        template <typename, typename>
        static std::false_type test(...);

        template <typename U, typename Paper>
        static auto test(int)
            -> decltype(std::declval<U>().serialize(
                            std::declval<Paper&>(), std::declval<std::string>()),
                        std::true_type());

    public:
        static constexpr bool value = std::is_same<decltype(test<T, PaperT>(0)), std::true_type>::value;
    };

}