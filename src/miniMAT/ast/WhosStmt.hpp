#ifndef MINIMAT_AST_WHOSSTMT_HPP
#define MINIMAT_AST_WHOSSTMT_HPP

#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct WhosStmt : public Statement {
            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;
        };
    }
}

#endif