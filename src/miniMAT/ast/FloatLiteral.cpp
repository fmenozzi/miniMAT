#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        void FloatLiteral::visit(Visitor& v) {
            v.VisitFloatLiteral(*this);
        }
    }
}
