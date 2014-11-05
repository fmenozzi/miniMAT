#include <LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::shared_ptr<Literal> literal) {
            this->literal = literal;
        }

        std::string LiteralExpr::GetClassName() const {
            return "LiteralExpr";
        }
    }
}
