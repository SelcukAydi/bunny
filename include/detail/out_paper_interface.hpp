#pragma once

namespace bunny::detail
{
    class OutPaperInterface
    {
        public:
        template<typename Paper, typename T>
        void operator() (Paper& paper, const T& data)
        {
            
        }
    };
}