#include <miniMAT/ast/IdRef.hpp>

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
            id->VisitDisplay(Indent(prefix));
        }

        ast::Matrix IdRef::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
            return vars->at(id->Spelling());
        }

        void IdRef::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                               std::shared_ptr<reporter::ErrorReporter> reporter) const {
            auto varname = id->Spelling();
            if (vars->find(varname) == vars->end())
                throw "Undefined function or variable \'" + varname + "\'.";
        }
    }
}
