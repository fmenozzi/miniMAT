#ifndef BINARY_EXPR_HPP
#define BINARY_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        class BinaryExpr : public Expression {
        public:
            BinaryExpr(std::unique_ptr<Expression> left,
                       std::unique_ptr<Operator> op,
                       std::unique_ptr<Expression> right);

            virtual ~BinaryExpr() {}

            void visit(DisplayVisitor& v, const std::string& prefix);

        private:
            std::unique_ptr<Expression> left;
            std::unique_ptr<Operator>   op;
            std::unique_ptr<Expression> right;
        };
    }
}

#endif
