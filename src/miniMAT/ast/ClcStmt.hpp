#ifndef MINIMAT_AST_CLCSTMT_HPP
#define MINIMAT_AST_CLCSTMT_HPP

#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct ClcStmt : public Statement 
        {
            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

            void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const;
        };
    }
}

#endif