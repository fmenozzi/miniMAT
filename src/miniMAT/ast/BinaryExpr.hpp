#ifndef BINARY_EXPR_HPP
#define BINARY_EXPR_HPP

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class BinaryExpr : public Expression {
        public:
            BinaryExpr(const Expression& left,
                       const Operator& op,
                       const Expression& right);

            void visit(const Visitor& v);

        private:
            // TODO Change this to use some kind of pointer
            Expression left;
            Operator   op;
            Expression right;
        };
    }
}

#endif
