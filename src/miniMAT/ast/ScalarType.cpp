#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        template <typename ArgType, typename ResultType>
        ScalarType<ArgType, ResultType>::ScalarType(TypeKind kind) {
            this->kind = kind;
        }

        template<typename ArgType, typename ResultType>
        ResultType ScalarType<ArgType, ResultType>::visit(
                                Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitScalarType(*this, arg);
        }
    }
}
