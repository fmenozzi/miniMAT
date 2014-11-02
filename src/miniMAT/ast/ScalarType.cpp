#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        ScalarType::ScalarType(TypeKind kind) {
            this->kind = kind;
        }

        ResultType ScalarType::visit(const Visitor& v) {
            v.VisitScalarType(*this);
        }
    }
}
