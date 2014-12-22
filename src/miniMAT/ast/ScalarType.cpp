#include <miniMAT/ast/ScalarType.hpp>

namespace miniMAT {
    namespace ast {
        std::string ScalarType::GetClassName() const {
            return "ScalarType";
        }

        void ScalarType::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(GetClassName()));
        }

        Matrix ScalarType::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            // TODO: This is really bad design
            return Matrix::Zero(1,1);
        }

        void ScalarType::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
