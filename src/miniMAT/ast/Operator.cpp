#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        void Operator::visit(DisplayVisitor& v, const std::string& prefix) {
            v.VisitOperator(this, prefix);
        }

        std::string Operator::GetClassName() const {
            return "Operator";
        }
    }
}
