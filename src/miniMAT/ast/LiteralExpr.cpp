#include <miniMAT/ast/LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::shared_ptr<Literal> literal) 
        {
            this->literal = literal;
        }

        std::string LiteralExpr::ClassName() const 
        {
            return "LiteralExpr";
        }

        std::shared_ptr<Literal> LiteralExpr::GetLiteral() const 
        {
            return literal;
        }

        void LiteralExpr::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            literal->VisitDisplay(Indent(prefix));
        }

        ast::Matrix LiteralExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            return literal->VisitEvaluate(vars);
        }

        void LiteralExpr::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                     std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {
            
        }

        void LiteralExpr::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                      ast::Matrix ans,
                                      bool suppressed) const 
        {
            
        }

        const std::shared_ptr<Reference>& LiteralExpr::GetRefFromRefExpr() const
        {
            return nullptr;
        }
    }
}
