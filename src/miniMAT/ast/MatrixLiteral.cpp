#include <miniMAT/ast/MatrixLiteral.hpp>

namespace miniMAT {
    namespace ast { 
        std::string MatrixLiteral::GetClassName() const {
            return "MatrixLiteral";
        }

        Matrix MatrixLiteral::GetMatrix() const {
            return mat;
        }

        void MatrixLiteral::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            auto r = std::to_string(mat.rows());
            auto c = std::to_string(mat.cols());

            Show(prefix, Quote(GetClassName()) + " " + Quote(r + "x" + c));
        }

        Matrix MatrixLiteral::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            return mat;
        }

        void MatrixLiteral::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                       std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
