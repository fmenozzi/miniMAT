#ifndef MINIMAT_UTIL_PRINTRESULT_HPP
#define MINIMAT_UTIL_PRINTRESULT_HPP

#include <miniMAT/ast/Matrix.hpp>

#include <string>

namespace miniMAT {
	namespace util {
		void PrintResult(const std::string& varname, Matrix m, bool suppressed);
	}
}

#endif 