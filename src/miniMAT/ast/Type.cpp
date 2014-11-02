#include <Type.hpp>

namespace miniMAT {
    namespace ast {
        Type::Type(TypeKind kind) {
            this->kind = kind;
        }

        TypeKind Type::GetKind() {
            return this->kind;
        }
    }
}
