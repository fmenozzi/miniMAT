#include <miniMAT/util/PrintResult.hpp>

#include <iostream>
#include <iomanip>
#include <cmath>

namespace miniMAT {
    namespace util {
        void PrintResult(const std::string& varname, Matrix m, bool suppressed) {
            if (!suppressed) {
                using namespace std;

                int maxdigits = log10(m.maxCoeff()) + 1;    // Get number of digits of max element
                int precision = 4;
                int space = 1, dot = 1;

                // Print a row at a time (default precision is 4)
                cout << varname << " =" << endl << endl;
                for (int i = 0; i < m.rows(); i++) {
                    cout << "    ";
                    for (int j = 0; j < m.cols(); j++)
                        cout << right 
                             << fixed 
                             << showpoint 
                             << setprecision(precision) 
                             << setw(maxdigits + precision + dot + space)
                             << m(i,j);
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
}