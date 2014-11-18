#include <Identifier.hpp>

namespace miniMAT {
    namespace ast {
        std::string Identifier::GetClassName() const {
            return "Identifier";
        }

        void Identifier::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        Matrix Identifier::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table) {
            // TODO: This is really bad design
            return Matrix::Zero(1,1);
        }

        void Identifier::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
