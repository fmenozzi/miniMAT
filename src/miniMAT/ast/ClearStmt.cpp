#include <miniMAT/ast/ClearStmt.hpp>
#include <miniMAT/ast/IdRef.hpp>

namespace miniMAT {
    namespace ast {
        ClearStmt::ClearStmt(std::vector<std::shared_ptr<Reference>> refs) {
            this->refs = refs;
        }

        std::string ClearStmt::GetClassName() const {
            return "ClearStmt";
        }

        void ClearStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            for (auto ref : refs)
            	ref->VisitDisplay(Indent(prefix));
        }

        Matrix ClearStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            if (refs.empty()) {
            	vars->erase(vars->begin(), vars->end());
            } else {
                for (auto ref : refs) {
                    // For now, all References are IdRefs
                    auto refspelling = std::dynamic_pointer_cast<IdRef>(ref)->id->GetSpelling();
                    if (vars->find(refspelling) != vars->end())
                        vars->erase(refspelling);
                }
            }

            return Matrix::Zero(0,0);
        }

        void ClearStmt::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                   std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
    }
}