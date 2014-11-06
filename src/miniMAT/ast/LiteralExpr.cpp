#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::shared_ptr<Literal> literal) {
            this->literal = literal;
        }

        std::string LiteralExpr::GetClassName() const {
            return "LiteralExpr";
        }

        void LiteralExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->literal->VisitDisplay(Indent(prefix));
        }

        double LiteralExpr::VisitEvaluate() const {
            return this->literal->VisitEvaluate();
        }
    }
}
