#ifndef MINIMAT_AST_ASSIGN_STMT_HPP
#define MINIMAT_AST_ASSIGN_STMT_HPP

#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
    namespace ast {
        struct AssignStmt : public Statement {
            AssignStmt(std::shared_ptr<Reference> ref,
                       std::shared_ptr<Expression> expr);

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

            std::shared_ptr<Reference> ref;
            std::shared_ptr<Expression> expr;

            Matrix val;
        };
    }
}

#endif
