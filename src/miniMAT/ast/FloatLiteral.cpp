#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        ResultType FloatLiteral<ArgType, ResultType>::visit(
                                Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitFloatLiteral(*this, arg);
        }
    }
}
