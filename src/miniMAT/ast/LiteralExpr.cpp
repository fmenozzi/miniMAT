#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::unique_ptr<Literal> literal) {
            this->literal = std::move(literal);
        }

        void LiteralExpr::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitLiteralExpr(*this, prefix);
        }
    }
}
