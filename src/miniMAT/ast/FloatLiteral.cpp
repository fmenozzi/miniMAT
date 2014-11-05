#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        void FloatLiteral::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitFloatLiteral(*this, prefix);
        }

        std::string FloatLiteral::GetClassName() {
            return "FloatLiteral";
        }
    }
}
