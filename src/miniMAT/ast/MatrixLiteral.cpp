#include <MatrixLiteral.hpp>
#include <sstream>

namespace miniMAT {
    namespace ast { 
        std::string MatrixLiteral::GetClassName() const {
            return "MatrixLiteral";
        }

        Matrix MatrixLiteral::GetMatrix() const {
            return this->mat;
        }

        void MatrixLiteral::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            auto r = std::to_string(this->mat.rows());
            auto c = std::to_string(this->mat.cols());

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(r + "x" + c));
        }

        Matrix MatrixLiteral::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            return this->mat;
        }

        void MatrixLiteral::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                      std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
