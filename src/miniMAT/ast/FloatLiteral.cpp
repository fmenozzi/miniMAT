#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        std::string FloatLiteral::GetClassName() const {
            return "FloatLiteral";
        }

        void FloatLiteral::VisitDisplay(const std::string& prefix) const {

        }
    }
}
