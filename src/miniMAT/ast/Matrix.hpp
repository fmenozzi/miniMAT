#ifndef MINIMAT_AST_MATRIX_HPP
#define MINIMAT_AST_MATRIX_HPP

#include <Eigen/Dense>

namespace miniMAT {
    namespace ast {
        using Matrix = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;
    }
}

#endif