#include <IdRef.hpp>

namespace miniMAT {
    namespace ast {
        IdRef::IdRef(std::shared_ptr<Identifier> id) {
            this->id  = id;
        }

        std::string IdRef::GetClassName() const {
            return "IdRef";
        }

        void IdRef::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->id->VisitDisplay(Indent(prefix));
        }

        double IdRef::VisitEvaluate() const {
            // TODO: This is really bad design
            return 1;
        }
    }
}
