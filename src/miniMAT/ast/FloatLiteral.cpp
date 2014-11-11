#include <FloatLiteral.hpp>
#include <sstream>

namespace miniMAT {
    namespace ast {
        std::string FloatLiteral::GetClassName() const {
            return "FloatLiteral";
        }

        void FloatLiteral::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, Quote(this->GetClassName()) + " " + Quote(this->GetSpelling()));
        }

        double FloatLiteral::VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) {
            std::istringstream iss(this->GetSpelling());
            double result;
            iss >> result;
            return result;
        }

        void FloatLiteral::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                      std::shared_ptr<reporter::ErrorReporter> reporter) const {
        }
    }
}
