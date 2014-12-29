#ifndef MINIMAT_AST_STATEMENT_HPP
#define MINIMAT_AST_STATEMENT_HPP

#include <miniMAT/ast/AST.hpp>
#include <miniMAT/visit/Visitors.hpp>

namespace miniMAT {
    namespace ast {
        struct Statement : public AST {
            virtual ~Statement() {}

            virtual std::string ClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
