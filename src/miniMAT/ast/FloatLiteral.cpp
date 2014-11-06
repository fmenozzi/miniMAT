#include <FloatLiteral.hpp>
#include <string>

namespace miniMAT {
    namespace ast {
        std::string FloatLiteral::GetClassName() const {
            return "FloatLiteral";
        }

        void FloatLiteral::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        double FloatLiteral::VisitEvaluate() const {
            return std::stod(this->GetSpelling());
        }
    }
}
