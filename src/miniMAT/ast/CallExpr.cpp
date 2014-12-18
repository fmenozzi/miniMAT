#include <miniMAT/ast/CallExpr.hpp>

namespace miniMAT {
	namespace ast {
		CallExpr::CallExpr(std::shared_ptr<Reference> function_ref, 
					 	   std::shared_ptr<ExprList> arg_list) {
			this->function_ref = function_ref;
			this->arg_list     = arg_list;
		}

		std::string CallExpr::GetClassName() const {
            return "CallExpr";
        }

        void CallExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->function_ref->VisitDisplay(Indent(prefix));
        }

        Matrix CallExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
        	


            return Matrix::Zero(0,0);



        }

        void CallExpr::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
            this->function_ref->VisitCheck(vars, reporter);
        }
	}
}