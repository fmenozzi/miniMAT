#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        /*
        ScalarType::ScalarType(TypeKind kind) {
            this->kind = kind;
        }
        */

        void ScalarType::visit(Visitor& v) {
            v.VisitScalarType(*this);
        }
    }
}
