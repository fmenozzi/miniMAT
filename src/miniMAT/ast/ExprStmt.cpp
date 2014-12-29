#include <miniMAT/ast/ExprStmt.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::shared_ptr<Expression> expr) {
            this->expr = expr;
        }

        std::string ExprStmt::ClassName() const {
            return "ExprStmt";
        }

        void ExprStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            expr->VisitDisplay(Indent(prefix));
        }

        ast::Matrix ExprStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            return expr->VisitEvaluate(vars);
        }

        void ExprStmt::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
            expr->VisitCheck(vars, reporter);
        }
    }
}
