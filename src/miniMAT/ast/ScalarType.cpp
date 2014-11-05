#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        /*
        ScalarType::ScalarType(TypeKind kind) {
            this->kind = kind;
        }
        */

        void ScalarType::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitScalarType(*this, prefix);
        }

        std::string ScalarType::GetClassName() const {
            return "ScalarType";
        }
    }
}
