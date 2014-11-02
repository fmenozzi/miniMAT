#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::shared_ptr<Literal> literal) {
            this->literal = literal;
        }

        void LiteralExpr::visit(Visitor& v) {
            v.VisitLiteralExpr(*this);
        }
    }
}
