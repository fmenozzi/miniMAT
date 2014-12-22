#ifndef MINIMAT_AST_CLEARSTMT_HPP
#define MINIMAT_AST_CLEARSTMT_HPP

#include <miniMAT/ast/Statement.hpp>
#include <miniMAT/ast/Reference.hpp>

#include <vector>
#include <memory>

namespace miniMAT {
	namespace ast {
		struct ClearStmt : public Statement {
			ClearStmt(std::vector<std::shared_ptr<Reference>> refs);

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;

            std::vector<std::shared_ptr<Reference>> refs;
		};
	}
}

#endif