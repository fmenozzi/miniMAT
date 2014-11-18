#include <BinaryExpr.hpp>
#include <cmath>

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

        Matrix BinaryExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table) {
            Matrix left_result  = this->left->VisitEvaluate(id_table);
            Matrix right_result = this->right->VisitEvaluate(id_table);

            // Check to see if both results are scalars
            if (left_result.rows() == right_result.rows() &&
                left_result.cols() == right_result.cols() &&
                left_result.rows() == 1 &&
                left_result.cols() == 1) {

                auto left_val  = left_result(0);
                auto right_val = right_result(0);

                Matrix result(1,1);

                std::string opstr = this->op->GetSpelling();
                if (opstr == "+") {
                    result << left_val + right_val;
                    return result;
                } else if (opstr == "-") {
                    result << left_val - right_val;
                    return result;
                } else if (opstr == "*") {
                    result << left_val * right_val;
                    return result;
                } else if (opstr == "/") {
                    result << left_val / right_val;
                    return result;
                } else { // ^
                    result << pow(left_val, right_val);
                    return result;
                }
            } else {
                // Non-scalar matrices

                //std::cout << "FINISH IMPLEMENTING BinaryExpr::VisitEvaluate!" << std::endl;
                return Matrix(0,0);
            }
        }

        void BinaryExpr::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
            this->left->VisitCheck(id_table, reporter);
            this->op->VisitCheck(id_table, reporter);
            this->right->VisitCheck(id_table, reporter);
        }
    }
}
