#include <miniMAT/util/PrintResult.hpp>
#include <miniMAT/util/NumDigits.hpp>

#include <iostream>
#include <iomanip>
#include <cmath>

namespace miniMAT {
    namespace util {
        void PrintResult(const std::string& varname, Matrix m, bool suppressed) {
            if (!suppressed) {
                using namespace std;

                int maxdigits = NumDigits(m.maxCoeff());
                int precision = 4;
                int space = 1, dot = 1;

                cout << varname << " =" << endl << endl;
                if (m.rows() == 1) {
                    // Even spacing between elements in a single row
                    for (int j = 0; j < m.cols(); j++)
                        cout << right << fixed << showpoint << setprecision(precision) <<  "   " << m(0, j);
                    cout << endl << endl;
                } else {
                    // More complex formatting for multiple rows
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
}