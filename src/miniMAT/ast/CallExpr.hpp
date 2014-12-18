#ifndef MINIMAT_AST_CALLEXPR_HPP
#define MINIMAT_AST_CALLEXPR_HPP

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/ExprList.hpp>

#include <memory>

namespace miniMAT {
	namespace ast {
		class CallExpr : public Expression {
		public:
			CallExpr(std::shared_ptr<Reference> functionref, 
					 std::shared_ptr<ExprList> arglist);

			std::string GetClassName() const;

			void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

		//private:
            std::shared_ptr<Reference> functionref;
            std::shared_ptr<ExprList>  arglist;
		};
	}
}

#endif