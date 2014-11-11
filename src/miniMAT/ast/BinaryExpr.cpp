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

        double BinaryExpr::VisitEvaluate() const {
            double left_result  = this->left->VisitEvaluate();
            double right_result = this->right->VisitEvaluate();

            std::string opstr = this->op->GetSpelling();
            if (opstr == "+")
                return left_result + right_result;
            else if (opstr == "-")
                return left_result - right_result;
            else if (opstr == "*")
                return left_result * right_result;
            else if (opstr == "/")
                return left_result / right_result;
            else // ^
                return pow(left_result, right_result);
        }

        void BinaryExpr::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
