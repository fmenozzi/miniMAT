#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class UnaryExpr : public Expression {
        public:
            UnaryExpr(const Operator& op,
                      const Expression& expr);

            void visit(const Visitor& v);

        private:
            // TODO Change this to use some kind of pointer
            Operator   op;
            Expression expr;
        };
    }
}

#endif
