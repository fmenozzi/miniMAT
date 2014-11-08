#include <Identifier.hpp>

namespace miniMAT {
    namespace ast {
        std::string Identifier::GetClassName() const {
            return "Identifier";
        }

        void Identifier::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        double Identifier::VisitEvaluate() const {
            // TODO: This is really bad design
            return 1;
        }
    }
}
