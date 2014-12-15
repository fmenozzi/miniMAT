#ifndef MINIMAT_AST_BINARY_EXPR_HPP
#define MINIMAT_AST_BINARY_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Operator.hpp>

namespace miniMAT {
    namespace ast {
        class BinaryExpr : public Expression {
        public:
            BinaryExpr(std::shared_ptr<Expression> left,
                       std::shared_ptr<Operator> op,
                       std::shared_ptr<Expression> right);

            virtual ~BinaryExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Expression> left;
            std::shared_ptr<Operator>   op;
            std::shared_ptr<Expression> right;
        };
    }
}

#endif
