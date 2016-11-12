#pragma once

#include <memory>

#if __cplusplus < 201402L && !defined(_WIN32)
    // std::make_unique is available from C++14 only
    namespace std {
        template<typename T, typename ...Args>
        std::unique_ptr<T> make_unique(Args&& ...args )
        {
            return std::unique_ptr<T>(new T(std::forward<Args>(args)... ));
        }
    }
#endif
