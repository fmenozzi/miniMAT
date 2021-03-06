#include <miniMAT/checker/Checker.hpp>

namespace miniMAT {
    namespace checker {
        Checker::Checker(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                         std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->vars     = vars;
            this->reporter = reporter;
        }

        std::shared_ptr<ast::AST> Checker::check(std::shared_ptr<ast::AST> ast) {
            try {
                ast->VisitCheck(vars, reporter);
                return ast;
            } catch (const std::string& error) {
                reporter->AddCheckError(error);
                return nullptr;
            }
        }
    }
}
