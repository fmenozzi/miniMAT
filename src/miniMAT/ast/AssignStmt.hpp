#ifndef ASSIGN_STMT_HPP
#define ASSIGN_STMT_HPP

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
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

        //private:
            std::shared_ptr<Reference> ref;
            std::shared_ptr<Expression> expr;

            Matrix val;
        };
    }
}

#endif
