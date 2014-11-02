#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::unique_ptr<Literal> literal) {
            this->literal = std::move(literal);
        }

        void LiteralExpr::visit(Visitor& v) {
            v.VisitLiteralExpr(*this);
        }
    }
}
