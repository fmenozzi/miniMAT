#include <memory>

#include <Checker.hpp>

namespace miniMAT {
    namespace checker {
        Checker::Checker(std::shared_ptr<std::map<std::string, double>> id_table,
                         std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->id_table = id_table;
            this->reporter = reporter;
        }

        std::shared_ptr<ast::AST> Checker::check(std::shared_ptr<ast::AST> ast) {
            try {
                ast->VisitCheck(this->id_table, this->reporter);
                return ast;
            } catch (...) {
                return nullptr;
            }
        }
    }
}
