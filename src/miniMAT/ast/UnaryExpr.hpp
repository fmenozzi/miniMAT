#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class UnaryExpr : public Expression {
        public:
            UnaryExpr(std::unique_ptr<Operator> op,
                      std::unique_ptr<Expression> expr);

            virtual ~UnaryExpr() {}

            void visit(Visitor& v);

        private:
            std::unique_ptr<Operator>   op;
            std::unique_ptr<Expression> expr;
        };
    }
}

#endif
