#include <memory>

#include <Checker.hpp>

#include <iostream>

namespace miniMAT {
    namespace checker {
        Checker::Checker(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                         std::shared_ptr<reporter::ErrorReporter> reporter) {
            this->id_table = id_table;
            this->reporter = reporter;
        }

        std::shared_ptr<ast::AST> Checker::check(std::shared_ptr<ast::AST> ast) {
            try {
                ast->VisitCheck(this->id_table, this->reporter);
                return ast;
            } catch (std::string error) {
                reporter->AddCheckError(error);
                return nullptr;
            }
        }
    }
}
