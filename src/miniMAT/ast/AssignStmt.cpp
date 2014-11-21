#include <AssignStmt.hpp>
#include <IdRef.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        AssignStmt::AssignStmt(std::shared_ptr<Reference> ref,
                               std::shared_ptr<Expression> expr) {
            this->ref  = ref;
            this->expr = expr;

            this->val  = Matrix::Zero(1,1);
        }

        std::string AssignStmt::GetClassName() const {
            return "AssignStmt";
        }

        void AssignStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->ref->VisitDisplay(Indent(prefix));
            this->expr->VisitDisplay(Indent(prefix));
        }

        Matrix AssignStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            if (ref->GetClassName() == "IdRef") {
                auto varname = std::dynamic_pointer_cast<IdRef>(ref)->id->GetSpelling();
                this->val = vars->at(varname);
            }
            return this->val;
        }

        void AssignStmt::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
            this->expr->VisitCheck(vars, reporter);

            if (ref->GetClassName() == "IdRef") {
                auto varname = std::dynamic_pointer_cast<IdRef>(ref)->id->GetSpelling();
                (*vars)[varname] = this->expr->VisitEvaluate(vars);
            }
        }
    }
}
