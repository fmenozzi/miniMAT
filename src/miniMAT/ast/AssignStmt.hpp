#ifndef MINIMAT_AST_ASSIGN_STMT_HPP
#define MINIMAT_AST_ASSIGN_STMT_HPP

#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct AssignStmt : public Statement 
        {
            AssignStmt(std::shared_ptr<Reference> ref,
                       std::shared_ptr<Expression> expr);

            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

            void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const;

            std::shared_ptr<Reference> ref;
            std::shared_ptr<Expression> expr;

            ast::Matrix val;
        };
    }
}

#endif
