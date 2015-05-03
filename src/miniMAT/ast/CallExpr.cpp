#include <miniMAT/ast/CallExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>

namespace miniMAT {
    namespace ast {
        CallExpr::CallExpr(std::shared_ptr<Reference> functionref, 
                           std::shared_ptr<ExprList> arglist) 
        {
            this->functionref = functionref;
            this->arglist     = arglist;
        }

        std::string CallExpr::ClassName() const 
        {
            return "CallExpr";
        }

        void CallExpr::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            functionref->VisitDisplay(Indent(prefix));
            for (auto& e : *arglist)
                e->VisitDisplay(Indent(prefix));
        }

        ast::Matrix CallExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            // For now, assume all call expressions are matrix indexing
            auto mat = functionref->VisitEvaluate(vars);
            ast::Matrix result(1,1);

            if (arglist->size() == 1) {
                auto indexmat = arglist->at(0)->VisitEvaluate(vars);

                auto index = static_cast<int>(indexmat(0));

                result(0) = mat(index-1);
            } else { // arglist->size() == 2
                auto indexmat1 = arglist->at(0)->VisitEvaluate(vars);
                auto indexmat2 = arglist->at(1)->VisitEvaluate(vars);

                auto index1 = static_cast<int>(indexmat1(0));
                auto index2 = static_cast<int>(indexmat2(0));

                result(0) = mat(index1-1, index2-1);
            }

            return result;
        }

        void CallExpr::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {
            functionref->VisitCheck(vars, reporter);

            // For now, assume all call expressions are matrix indexing (i.e. requires 1 or 2 args)
            if (arglist->size() < 1 or arglist->size() > 2)
                throw std::string("Incorrect number of args in matrix index");

            for (auto& e : *arglist)
                e->VisitCheck(vars, reporter);

            // Make sure that indices don't go out of bounds
            for (auto e : *arglist) {
                auto indexval = e->VisitEvaluate(vars)(0);
                auto mat = functionref->VisitEvaluate(vars);
                if (indexval < 1 or indexval > mat.size())
                    throw std::string("Index out of bounds");
            }
        }

        void CallExpr::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                   ast::Matrix ans,
                                   bool suppressed) const 
        {
            
        }

        const std::shared_ptr<Reference>& CallExpr::GetRefFromRefExpr() const
        {
            return nullptr;
        }

        const std::shared_ptr<Literal>& CallExpr::GetLiteralFromLiteralExpr() const
        {
            return nullptr;
        }
    }
}