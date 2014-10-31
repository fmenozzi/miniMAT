#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        Operator::Operator(const Token& token) {
            this->token = token;
        }

        template<typename ArgType, typename ResultType>
        ResultType Operator::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitOperator(*this, arg);
        }
    }
}
