#include <miniMAT/ast/RefExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        RefExpr::RefExpr(std::shared_ptr<Reference> ref) 
        {
            this->ref = ref;
        }

        std::string RefExpr::ClassName() const 
        {
            return "RefExpr";
        }

        void RefExpr::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            ref->VisitDisplay(Indent(prefix));
        }

        ast::Matrix RefExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            return ref->VisitEvaluate(vars);
        }

        void RefExpr::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {
            if (ref->ClassName() == "IdRef") {
                auto varname = ref->RefSpelling();
                if (vars->find(varname) == vars->end())
                    throw "Undefined function or variable \'" + varname + "\'.";
            }
        }

        void RefExpr::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                             ast::Matrix ans,
                             bool suppressed) const 
        {
            
        }

        const std::shared_ptr<Reference>& RefExpr::GetRefFromRefExpr() const
        {
            return ref;
        }

        const std::shared_ptr<Literal>& RefExpr::GetLiteralFromLiteralExpr() const
        {
            return nullptr;
        }
    }
}
