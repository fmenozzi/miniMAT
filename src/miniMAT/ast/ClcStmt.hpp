#ifndef MINIMAT_AST_CLCSTMT_HPP
#define MINIMAT_AST_CLCSTMT_HPP

#include <miniMAT/ast/Statement.hpp>

namespace miniMAT {
	namespace ast {
		class ClcStmt : public Statement {
		public:
			std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> checker) const;
		};
	}
}

#endif