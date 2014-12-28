#include <miniMAT/ast/RefExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        RefExpr::RefExpr(std::shared_ptr<Reference> ref) {
            this->ref = ref;
        }

        std::string RefExpr::GetClassName() const {
            return "RefExpr";
        }

        std::shared_ptr<Reference> RefExpr::GetReference() const {
            return ref;
        }

        void RefExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            ref->VisitDisplay(Indent(prefix));
        }

        ast::Matrix RefExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            return ref->VisitEvaluate(vars);
        }

        void RefExpr::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const {
            if (ref->GetClassName() == "IdRef") {
                auto varname = std::dynamic_pointer_cast<IdRef>(ref)->id->Spelling();
                if (vars->find(varname) == vars->end()) {
                    throw "Undefined function or variable \'" + varname + "\'.";
                }
            }
        }
    }
}
