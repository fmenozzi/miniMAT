#include <miniMAT/ast/MatrixLiteral.hpp>

namespace miniMAT {
    namespace ast { 
        std::string MatrixLiteral::ClassName() const 
        {
            return "ast::MatrixLiteral";
        }

        void MatrixLiteral::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            auto r = std::to_string(mat.rows());
            auto c = std::to_string(mat.cols());

            Show(prefix, Quote(ClassName()) + " " + Quote(r + "x" + c));
        }

        ast::Matrix MatrixLiteral::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            return mat;
        }

        void MatrixLiteral::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                       std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {

        }

        void MatrixLiteral::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                        ast::Matrix ans,
                                        bool suppressed) const 
        {
            
        }
    }
}
