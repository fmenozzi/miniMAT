#include <BinaryExpr.hpp>
#include <LiteralExpr.hpp>
#include <RefExpr.hpp>
#include <MatrixLiteral.hpp>
#include <IdRef.hpp>
#include <Dims.hpp>

#include <cmath>
#include <iostream>

namespace miniMAT {
    namespace ast {
        BinaryExpr::BinaryExpr(std::shared_ptr<Expression> left,
                               std::shared_ptr<Operator> op,
                               std::shared_ptr<Expression> right) {
            this->left  = left;
            this->op    = op;
            this->right = right;
        }

        std::string BinaryExpr::GetClassName() const {
            return "BinaryExpr";
        }

        void BinaryExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->op->VisitDisplay(Indent(prefix));
            this->left->VisitDisplay(Indent(Indent(prefix)));
            this->right->VisitDisplay(Indent(Indent(prefix)));
        }

        Matrix BinaryExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            using namespace miniMAT::util;

            Matrix lresult = this->left->VisitEvaluate(vars);
            Matrix rresult = this->right->VisitEvaluate(vars);

            auto opstr = this->op->GetSpelling();
            if (opstr == "+" || opstr == "-") {
                // Check for scalar-matrix or matrix-scalar addition/subtraction
                if (Dims::scalar_mat(lresult, rresult))
                    lresult = Matrix::Constant(rresult.rows(), rresult.cols(), lresult(0));
                else if (Dims::mat_scalar(lresult, rresult))
                    rresult = Matrix::Constant(lresult.rows(), lresult.cols(), rresult(0));

                if (opstr == "+")
                    return lresult + rresult;
                else
                    return lresult - rresult;
            } else if (opstr == "*") {
                // Check for scalar-matrix or matrix-scalar multiplication
                if (Dims::scalar_mat(lresult, rresult))
                    return lresult(0) * rresult;
                if (Dims::mat_scalar(lresult, rresult))
                    return lresult * rresult(0);

                // Must be matrix-matrix multiplication
                return lresult * rresult;
            } else if (opstr == "/") {
                // Check for matrix-scalar division
                if (Dims::mat_scalar(lresult, rresult))
                    return lresult / rresult(0);

                // Must be scalar-scalar division
                Matrix result(1,1);
                result << lresult(0) / rresult(0);
                return result;
            } else { // ^
                // Must be scalar-scalar exponentiation
                Matrix result(1,1);
                result << std::pow(lresult(0), rresult(0));
                return result;
            }
        }

        void BinaryExpr::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
            using namespace miniMAT::util;

            // Extract matrix values from expressions
            Matrix lresult, rresult;
            bool left_not_initialized = true, right_not_initialized = true;
            if (left->GetClassName() == "LiteralExpr") {
                auto lliteralexpr   = std::dynamic_pointer_cast<ast::LiteralExpr>(left);
                auto lliteral       = lliteralexpr->GetLiteral();
                auto lmatrixliteral = std::dynamic_pointer_cast<ast::MatrixLiteral>(lliteral);
                lresult             = lmatrixliteral->GetMatrix();

                left_not_initialized = false;
            } 

            if (right->GetClassName() == "LiteralExpr") {
                auto rliteralexpr   = std::dynamic_pointer_cast<ast::LiteralExpr>(right);
                auto rliteral       = rliteralexpr->GetLiteral();
                auto rmatrixliteral = std::dynamic_pointer_cast<ast::MatrixLiteral>(rliteral);
                rresult             = rmatrixliteral->GetMatrix();

                right_not_initialized = false;
            } 

            left->VisitCheck(vars, reporter);
            right->VisitCheck(vars, reporter);

            if (left_not_initialized)
                lresult = left->VisitEvaluate(vars);
            if (right_not_initialized)
                rresult = right->VisitEvaluate(vars);
            
            // Check for dimension requirements (if present)
            auto opstr = op->GetSpelling();
            if (opstr == "+" || opstr == "-") {
                if (Dims::mat_mat(lresult, rresult) && ! Dims::dims_match(lresult, rresult))
                    throw std::string("Mismatched dimensions");
            } else if (opstr == "*") {
                if (Dims::mat_mat(lresult, rresult) && ! Dims::can_multiply(lresult, rresult))
                    throw std::string("Mismatched dimensions");
            } else if (opstr == "/") {
                if (! Dims::mat_scalar(lresult, rresult) && ! Dims::scalar_scalar(lresult, rresult))
                    throw std::string("Mismatched dimensions");
            } else { // ^
                if (! Dims::scalar_scalar(lresult, rresult))
                    throw std::string("Mismatched dimensions");
            }
            //*/
        }
    }
}