#include <AssignStmt.hpp>
#include <IdRef.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        AssignStmt::AssignStmt(std::shared_ptr<Reference> ref,
                               std::shared_ptr<Expression> expr) {
            this->ref  = ref;
            this->expr = expr;

            this->val  = 0;
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

        double AssignStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) {
            this->val = this->expr->VisitEvaluate(id_table);
            return this->val;
        }

        void AssignStmt::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
            if (ref->GetClassName() == "IdRef") {
                auto varname = std::dynamic_pointer_cast<IdRef>(ref)->id->GetSpelling();
                (*id_table)[varname] = this->expr->VisitEvaluate(id_table);
            }
        }
    }
}
