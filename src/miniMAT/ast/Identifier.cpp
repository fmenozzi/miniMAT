#include <miniMAT/ast/Identifier.hpp>

namespace miniMAT {
    namespace ast {
        std::string Identifier::GetClassName() const {
            return "Identifier";
        }

        void Identifier::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(GetClassName()) + " " + Quote(Spelling()));
        }

        Matrix Identifier::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            // TODO: This is really bad design
            return Matrix::Zero(1,1);
        }

        void Identifier::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
