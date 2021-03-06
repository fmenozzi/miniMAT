#ifndef MINIMAT_AST_CLEARSTMT_HPP
#define MINIMAT_AST_CLEARSTMT_HPP

#include <miniMAT/ast/Statement.hpp>
#include <miniMAT/ast/Reference.hpp>

#include <vector>
#include <memory>

namespace miniMAT {
    namespace ast {
        struct ClearStmt : public Statement 
        {
            ClearStmt(std::vector<std::shared_ptr<Reference>> refs);

            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

            void PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const;

            std::vector<std::shared_ptr<Reference>> refs;
        };
    }
}

#endif