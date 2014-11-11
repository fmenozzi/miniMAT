#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        std::string Operator::GetClassName() const {
            return "Operator";
        }

        void Operator::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        double Operator::VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) {
            // TODO: This is really bad design
            return -1;
        }

        void Operator::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                  std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
