#include <miniMAT/ast/Operator.hpp>

namespace miniMAT {
    namespace ast {
        std::string Operator::ClassName() const 
        {
            return "Operator";
        }

        void Operator::VisitDisplay(const std::string& prefix) const 
        {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(ClassName()) + " " + Quote(Spelling()));
        }

        ast::Matrix Operator::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) 
        {
            // TODO: This is really bad design
            return ast::Matrix::Zero(1,1);
        }

        void Operator::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const 
        {

        }

        void Operator::PrintResult(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                   ast::Matrix ans,
                                   bool suppressed) const 
        {

        }
    }
}
