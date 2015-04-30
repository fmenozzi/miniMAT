#include <miniMAT/ast/AssignStmt.hpp>
#include <miniMAT/ast/IdRef.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        AssignStmt::AssignStmt(std::shared_ptr<Reference> ref,
                               std::shared_ptr<Expression> expr) {
            this->ref  = ref;
            this->expr = expr;

            this->val  = ast::Matrix::Zero(1,1);
        }

        std::string AssignStmt::ClassName() const {
            return "AssignStmt";
        }

        void AssignStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            ref->VisitDisplay(Indent(prefix));
            expr->VisitDisplay(Indent(prefix));
        }

        ast::Matrix AssignStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            if (ref->ClassName() == "IdRef")
                val = vars->at(ref->RefSpelling());
            return val;
        }

        void AssignStmt::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
            expr->VisitCheck(vars, reporter);

            if (ref->ClassName() == "IdRef")
                (*vars)[ref->RefSpelling()] = expr->VisitEvaluate(vars);
        }
    }
}
