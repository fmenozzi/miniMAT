#ifndef MINIMAT_AST_CALLEXPR_HPP
#define MINIMAT_AST_CALLEXPR_HPP

#include <miniMAT/ast/Expression.hpp>
#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/ExprList.hpp>

#include <memory>

namespace miniMAT {
	namespace ast {
		class CallExpr : public Expression {
			CallExpr(std::shared_ptr<Reference> function_ref, 
					 std::shared_ptr<ExprList> arg_list);

			std::string GetClassName() const;

			void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

		//private:
            std::shared_ptr<Reference> function_ref;
            std::shared_ptr<ExprList>  arg_list;
		};
	}
}

#endif