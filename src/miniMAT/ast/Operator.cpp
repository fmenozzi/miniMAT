#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        /*
        Operator::Operator(std::unique_ptr<lexer::Token> token) {
            this->token = std::move(token);
        }
        */

        void Operator::visit(Visitor& v) {
            v.VisitOperator(*this);
        }
    }
}
