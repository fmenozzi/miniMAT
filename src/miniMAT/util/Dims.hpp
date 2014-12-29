#ifndef MINIMAT_UTIL_DIMS_HPP
#define MINIMAT_UTIL_DIMS_HPP

#include <miniMAT/ast/Matrix.hpp>

namespace miniMAT {
    namespace util {
        // Convenience functions for determining validity of expressions dimension-wise
        class Dims {
        public:
            static bool is_scalar(ast::Matrix m);
            static bool dims_match(ast::Matrix l, ast::Matrix r);
            static bool can_multiply(ast::Matrix l, ast::Matrix r);

            static bool scalar_mat(ast::Matrix l, ast::Matrix r);
            static bool mat_scalar(ast::Matrix l, ast::Matrix r);
            static bool scalar_scalar(ast::Matrix l, ast::Matrix r);
            static bool mat_mat(ast::Matrix l, ast::Matrix r);
        };
    }
}

#endif