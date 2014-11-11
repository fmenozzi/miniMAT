#include <IdRef.hpp>

namespace miniMAT {
    namespace ast {
        IdRef::IdRef(std::shared_ptr<Identifier> id) {
            this->id  = id;
        }

        std::string IdRef::GetClassName() const {
            return "IdRef";
        }

        void IdRef::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
            this->id->VisitDisplay(Indent(prefix));
        }

        double IdRef::VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) {
            return id_table->at(this->id->GetSpelling());
        }

        void IdRef::VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                               std::shared_ptr<reporter::ErrorReporter> reporter) const {
            auto varname = this->id->GetSpelling();
            if (id_table->find(varname) == id_table->end())
                throw "Undefined variable or function \'" + varname + "\'.";
        }
    }
}
