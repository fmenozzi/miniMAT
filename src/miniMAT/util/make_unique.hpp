#ifndef MINIMAT_UTIL_MAKEUNIQUE_HPP
#define MINIMAT_UTIL_MAKEUNIQUE_HPP

#include <memory>

namespace miniMAT {
    namespace util {
        template <typename T, typename... Args>
        std::unique_ptr<T> make_unique(Args&&... args) {
            return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
        }
    }
}

#endif