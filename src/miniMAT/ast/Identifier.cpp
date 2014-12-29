#include <miniMAT/ast/Identifier.hpp>

namespace miniMAT {
    namespace ast {
        std::string Identifier::ClassName() const {
            return "Identifier";
        }

        void Identifier::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(ClassName()) + " " + Quote(Spelling()));
        }

        ast::Matrix Identifier::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            // TODO: This is really bad design
            return ast::Matrix::Zero(1,1);
        }

        void Identifier::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
