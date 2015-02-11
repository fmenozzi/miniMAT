#include <miniMAT/util/NumDigits.hpp>

#include <cmath>

namespace miniMAT {
    namespace util {
        int NumDigits(double num) {
            return num == 0 ? 1 : fabs(log10(num)) + 1;
        }
    }
}