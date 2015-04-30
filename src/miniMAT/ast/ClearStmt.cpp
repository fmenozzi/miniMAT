#include <miniMAT/ast/ClearStmt.hpp>
#include <miniMAT/ast/IdRef.hpp>

namespace miniMAT {
    namespace ast {
        ClearStmt::ClearStmt(std::vector<std::shared_ptr<Reference>> refs) {
            this->refs = refs;
        }

        std::string ClearStmt::ClassName() const {
            return "ClearStmt";
        }

        void ClearStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            for (auto ref : refs)
                ref->VisitDisplay(Indent(prefix));
        }

        ast::Matrix ClearStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            if (refs.empty()) {
                vars->erase(vars->begin(), vars->end());
            } else {
                // Check for "clear all"
                if (refs.size() == 1) {
                    if (refs[0]->RefSpelling() == "all")
                        vars->erase(vars->begin(), vars->end());
                }

                for (auto ref : refs) {
                    // For now, all References are IdRefs
                    auto refspelling = ref->RefSpelling();
                    if (vars->find(refspelling) != vars->end())
                        vars->erase(refspelling);
                }
            }

            return ast::Matrix::Zero(0,0);
        }

        void ClearStmt::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                   std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
    }
}