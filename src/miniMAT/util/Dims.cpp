#include <miniMAT/util/Dims.hpp>

namespace miniMAT {
	namespace util {
		bool Dims::is_scalar(ast::Matrix m) {
			return m.rows() == 1 and m.cols() == 1;
		}

		bool Dims::dims_match(ast::Matrix l, ast::Matrix r) {
			return l.rows() == r.rows() and l.cols() == r.cols();
		}

		bool Dims::can_multiply(ast::Matrix l, ast::Matrix r) {
			return l.cols() == r.rows();
		}

		bool Dims::scalar_mat(ast::Matrix l, ast::Matrix r) {
			return is_scalar(l) and not is_scalar(r);
		}

		bool Dims::mat_scalar(ast::Matrix l, ast::Matrix r) {
			return not is_scalar(l) and is_scalar(r);
		}

		bool Dims::scalar_scalar(ast::Matrix l, ast::Matrix r) {
			return is_scalar(l) and is_scalar(r);
		}

		bool Dims::mat_mat(ast::Matrix l, ast::Matrix r) {
			return not is_scalar(l) and not is_scalar(r);
		}
	}
}