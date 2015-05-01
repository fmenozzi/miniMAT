#include <miniMAT/ast/ExprStmt.hpp>

#include <miniMAT/ast/RefExpr.hpp>
#include <miniMAT/ast/IdRef.hpp>
#include <miniMAT/util/PrintResult.hpp>

namespace miniMAT {
    namespace ast {
        ExprStmt::ExprStmt(std::shared_ptr<Expression> expr) 
        {
            this->expr = expr;
        }

        std::string ExprStmt::ClassName() const 
        {
            return "ExprStmt";
        }

        void ExprStmt::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            expr->VisitDisplay(Indent(prefix));
        }

        ast::Matrix ExprStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            return expr->VisitEvaluate(vars);
        }

        void ExprStmt::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {
            expr->VisitCheck(vars, reporter);
        }

        void ExprStmt::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                   ast::Matrix ans,
                                   bool suppressed) const 
        {
    
            if (expr->ClassName() == "RefExpr") {
                auto refexpr = std::dynamic_pointer_cast<ast::RefExpr>(expr);
                auto varname = refexpr->ref->RefSpelling();

                util::PrintResult(varname, vars->at(varname), suppressed);
            } else {
                (*vars)["ans"] = ans;

                util::PrintResult("ans", ans, suppressed);
            }
        }
    }
}
