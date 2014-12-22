#include <miniMAT/util/PrintResult.hpp>

#include <iostream>
#include <iomanip>

namespace miniMAT {
	namespace util {
		void PrintResult(std::string varname, Matrix m, bool suppressed) {
			if (!suppressed) {
                // Print a row at a time (default precision is 4)
                std::cout << varname << " =" << std::endl << std::endl;
                for (int i = 0; i < m.rows(); i++) {
                    std::cout << "    ";
                    for (int j = 0; j < m.cols(); j++)
                        std::cout << std::fixed << std::showpoint << std::setprecision(4) << m(i,j) << " ";
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
		}
	}
}