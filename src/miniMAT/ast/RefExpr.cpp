#include <RefExpr.hpp>

namespace miniMAT {
    namespace ast {
        RefExpr::RefExpr(std::shared_ptr<Reference> ref) {
            this->ref = ref;

            this->val = 0;
        }

        std::string RefExpr::GetClassName() const {
            return "RefExpr";
        }

        void RefExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->ref->VisitDisplay(Indent(prefix));
        }

        double RefExpr::VisitEvaluate() const {
            // TODO: This is really bad design

            // Maybe we should store the value of
            return val;
        }

        void RefExpr::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
