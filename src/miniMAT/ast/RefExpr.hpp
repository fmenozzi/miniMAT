#ifndef MINIMAT_AST_REF_EXPR_HPP
#define MINIMAT_AST_REF_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Reference.hpp>

namespace miniMAT {
    namespace ast {
        struct RefExpr : public Expression {
            RefExpr(std::shared_ptr<Reference> ref);

            std::string                ClassName() const;
            std::shared_ptr<Reference> GetReference() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            std::shared_ptr<Reference> ref;
        };
    }
}

#endif
