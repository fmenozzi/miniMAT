#include <miniMAT/util/Dims.hpp>

namespace miniMAT {
	namespace util {
		bool Dims::is_scalar(Matrix m) {
			return m.rows() == 1 && m.cols() == 1;
		}

		bool Dims::dims_match(Matrix l, Matrix r) {
			return l.rows() == r.rows() && l.cols() == r.cols();
		}

		bool Dims::can_multiply(Matrix l, Matrix r) {
			return l.cols() == r.rows();
		}

		bool Dims::scalar_mat(Matrix l, Matrix r) {
			return is_scalar(l) && ! is_scalar(r);
		}

		bool Dims::mat_scalar(Matrix l, Matrix r) {
			return ! is_scalar(l) && is_scalar(r);
		}

		bool Dims::scalar_scalar(Matrix l, Matrix r) {
			return is_scalar(l) && is_scalar(r);
		}

		bool Dims::mat_mat(Matrix l, Matrix r) {
			return ! is_scalar(l) && ! is_scalar(r);
		}
	}
}