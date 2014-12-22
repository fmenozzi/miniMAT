#include <miniMAT/ast/LiteralExpr.hpp>

namespace miniMAT {
    namespace ast {
        LiteralExpr::LiteralExpr(std::shared_ptr<Literal> literal) {
            this->literal = literal;
        }

        std::string LiteralExpr::GetClassName() const {
            return "LiteralExpr";
        }

        std::shared_ptr<Literal> LiteralExpr::GetLiteral() const {
            return literal;
        }

        void LiteralExpr::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            literal->VisitDisplay(Indent(prefix));
        }

        Matrix LiteralExpr::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            return literal->VisitEvaluate(vars);
        }

        void LiteralExpr::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                     std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
