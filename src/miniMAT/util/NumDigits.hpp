#ifndef MINIMAT_UTIL_NUMDIGITS_HPP
#define MINIMAT_UTIL_NUMDIGITS_HPP

namespace miniMAT {
    namespace util {
        int NumDigits(double num) {
            return num == 0 ? 1 : fabs(log10(num)) + 1;
        }
    }
}

#endif 