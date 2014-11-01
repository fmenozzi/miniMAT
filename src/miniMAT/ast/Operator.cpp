#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        Operator<ArgType, ResultType>::Operator(const lexer::Token& token) {
            this->token = token;
        }

        template<typename ArgType, typename ResultType>
        ResultType Operator<ArgType, ResultType>::visit(
                                Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitOperator(*this, arg);
        }
    }
}
