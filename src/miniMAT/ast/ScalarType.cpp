#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        ScalarType::ScalarType(TypeKind kind) {
            this->kind = kind;
        }

        template<typename ArgType, typename ResultType>
        ResultType ScalarType::visit(Visitor<ArgType, ResultType> v, ArgType arg) {
            return v.VisitScalarType(*this, arg);
        }
    }
}
