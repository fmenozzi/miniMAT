#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        Operator::Operator(const lexer::Token& token) {
            this->token = token;
        }

        void Operator::visit(const Visitor& v) {
            v.VisitOperator(*this);
        }
    }
}
