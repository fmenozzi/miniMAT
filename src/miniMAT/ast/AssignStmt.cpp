#include <AssignStmt.hpp>

namespace miniMAT {
    namespace ast {
        AssignStmt::AssignStmt(std::shared_ptr<Reference> ref,
                               std::shared_ptr<Expression> expr) {
            this->ref  = ref;
            this->expr = expr;
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

        double AssignStmt::VisitEvaluate() const {
            return this->expr->VisitEvaluate();
        }
    }
}
