#include <miniMAT/ast/UnaryExpr.hpp>

namespace miniMAT {
    namespace ast {
        UnaryExpr::UnaryExpr(std::shared_ptr<Operator> op,
                             std::shared_ptr<Expression> expr) 
        {
            this->op   = op;
            this->expr = expr;
        }

        std::string UnaryExpr::ClassName() const 
        {
            return "UnaryExpr";
        }

        void UnaryExpr::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            op->VisitDisplay(Indent(prefix));
            expr->VisitDisplay(Indent(Indent(prefix)));
        }

        ast::Matrix UnaryExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            ast::Matrix result = expr->VisitEvaluate(vars);
            if (op->Spelling() == "-")
                result *= -1;
            return result;
        }

        void UnaryExpr::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                   std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {
            op->VisitCheck(vars, reporter);
            expr->VisitCheck(vars, reporter);
        }

        void UnaryExpr::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    ast::Matrix ans,
                                    bool suppressed) const 
        {
            
        }

        const std::shared_ptr<Reference>& UnaryExpr::GetRefFromRefExpr() const
        {
            return nullptr;
        }
    }
}
