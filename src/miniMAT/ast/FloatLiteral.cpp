#include <FloatLiteral.hpp>

namespace miniMAT {
    namespace ast {
        std::string FloatLiteral::GetClassName() const {
            return "FloatLiteral";
        }

        void FloatLiteral::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }
    }
}
