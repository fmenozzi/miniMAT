#include <RefExpr.hpp>
#include <IdRef.hpp>
#include <iostream>

namespace miniMAT {
    namespace ast {
        RefExpr::RefExpr(std::shared_ptr<Reference> ref) {
            this->ref = ref;
        }

        std::string RefExpr::GetClassName() const {
            return "RefExpr";
        }

        void RefExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->ref->VisitDisplay(Indent(prefix));
        }

        double RefExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) {
            return this->ref->VisitEvaluate(id_table);
        }

        void RefExpr::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const {
            if (ref->GetClassName() == "IdRef") {
                auto varname = std::dynamic_pointer_cast<IdRef>(ref)->id->GetSpelling();
                if (id_table->find(varname) == id_table->end()) {
                    throw "Undefined variable or function \'" + varname + "\'.";
                }
            }
        }
    }
}
