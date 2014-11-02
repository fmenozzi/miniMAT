#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        void FloatLiteral::visit(const Visitor& v) {
            v.VisitFloatLiteral(*this);
        }
    }
}
