#include <miniMAT/ast/Operator.hpp>

namespace miniMAT {
    namespace ast {
        std::string Operator::GetClassName() const {
            return "Operator";
        }

        void Operator::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(GetClassName()) + " " + Quote(GetSpelling()));
        }

        Matrix Operator::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            // TODO: This is really bad design
            return Matrix::Zero(1,1);
        }

        void Operator::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
