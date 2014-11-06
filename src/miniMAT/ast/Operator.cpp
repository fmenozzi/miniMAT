#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        std::string Operator::GetClassName() const {
            return "Operator";
        }

        void Operator::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        double Operator::VisitEvaluate() const {
            // TODO: This is bad design
            return -1;
        }
    }
}
