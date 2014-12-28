#ifndef MINIMAT_AST_WHOSTMT_HPP
#define MINIMAT_AST_WHOSTMT_HPP

#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct WhoStmt : public Statement {
            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;
        };
    }
}

#endif