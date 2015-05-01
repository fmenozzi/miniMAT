#ifndef MINIMAT_AST_CALLEXPR_HPP
#define MINIMAT_AST_CALLEXPR_HPP

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/ExprList.hpp>

#include <memory>

namespace miniMAT {
    namespace ast {
        struct CallExpr : public Expression 
        {
            CallExpr(std::shared_ptr<Reference> functionref, 
                     std::shared_ptr<ExprList> arglist);

            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const;

            std::shared_ptr<Reference> functionref;
            std::shared_ptr<ExprList>  arglist;
        };
    }
}

#endif