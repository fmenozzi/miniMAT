#ifndef MINIMAT_AST_MATRIX_HPP
#define MINIMAT_AST_MATRIX_HPP

#include <eigen3/Eigen/Dense>

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> Matrix;

#endif