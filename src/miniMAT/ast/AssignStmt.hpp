#ifndef ASSIGN_STMT_HPP
#define ASSIGN_STMT_HPP

#include <memory>
#include <string>

#include <Reference.hpp>
#include <Expression.hpp>
#include <Statement.hpp>

namespace miniMAT {
    namespace ast {
        class AssignStmt : public Statement {
        public:
            AssignStmt(std::shared_ptr<Reference> ref,
                       std::shared_ptr<Expression> expr);

            virtual ~AssignStmt() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            double VisitEvaluate() const;

        //private:
            std::shared_ptr<Reference> ref;
            std::shared_ptr<Expression> expr;
        };
    }
}

#endif
