#include <miniMAT/util/NumDigits.hpp>

#include <cmath>

namespace miniMAT {
    namespace util {
        int NumDigits(double num) {
            return log10(num) + 1;
        }
    }
}