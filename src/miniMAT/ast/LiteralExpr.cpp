#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(const Literal& literal) {
            // TODO Change this to use some kind of pointer
            this->literal = literal;
        }

        void LiteralExpr::visit(const Visitor& v) {
            v.VisitLiteralExpr(*this);
        }
    }
}
