#ifndef MINIMAT_AST_REF_EXPR_HPP
#define MINIMAT_AST_REF_EXPR_HPP

#include <memory>

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Reference.hpp>

namespace miniMAT {
    namespace ast {
        class RefExpr : public Expression {
        public:
            RefExpr(std::shared_ptr<Reference> ref);

            std::string                GetClassName() const;
            std::shared_ptr<Reference> GetReference() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Reference> ref;
        };
    }
}

#endif
