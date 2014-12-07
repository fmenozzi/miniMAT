#ifndef MINIMAT_UTIL_UTIL_HPP
#define MINIMAT_UTIL_UTIL_HPP

#include <map>
#include <string>
#include <functional>
#include <memory>

#include <Matrix.hpp>

namespace miniMAT {
    namespace util {
        class Util {
        public:
            static std::map<std::string, std::function<void(void)>> funcs;

            static void init(std::shared_ptr<std::map<std::string, Matrix>> vars);

            static void PrintResult(std::string varname, Matrix m, bool suppressed);
            static std::function<void(void)> GetFunction(const std::string& s);
            static bool HasFunction(const std::string& s);
        };
    }
}

#endif