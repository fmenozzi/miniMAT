#ifndef MINIMAT_UTIL_DIMS_HPP
#define MINIMAT_UTIL_DIMS_HPP

#include <Matrix.hpp>

namespace miniMAT {
	namespace util {
		// Convenience functions for determining validity of expressions dimension-wise
		class Dims {
		public:
			static bool is_scalar(Matrix m);
			static bool dims_match(Matrix l, Matrix r);
			static bool can_multiply(Matrix l, Matrix r);

			static bool scalar_mat(Matrix l, Matrix r);
			static bool mat_scalar(Matrix l, Matrix r);
			static bool scalar_scalar(Matrix l, Matrix r);
			static bool mat_mat(Matrix l, Matrix r);
		};
	}
}

#endif