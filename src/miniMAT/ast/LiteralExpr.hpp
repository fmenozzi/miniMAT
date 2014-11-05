#ifndef LITERAL_EXPR_HPP
#define LITERAL_EXPR_HPP

#include <memory>
#include <string>

#include <Expression.hpp>
#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class LiteralExpr : public Expression {
        public:
            LiteralExpr(std::unique_ptr<Literal> literal);

            virtual ~LiteralExpr() {}

            void visit(DisplayVisitor& v, const std::string& prefix);

            std::string GetClassName();

        private:
            std::unique_ptr<Literal> literal;
        };
    }
}

#endif
