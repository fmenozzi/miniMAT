#include <ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        std::string ScalarType::GetClassName() const {
            return "ScalarType";
        }

        void ScalarType::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            // TODO: Once we get that linker bug fixed, we'll add the TypeKind
            Show(prefix, Quote(this->GetClassName()));
        }
    }
}
