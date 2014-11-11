#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <map>
#include <string>
#include <memory>

#include <ErrorReporter.hpp>
#include <AST.hpp>

namespace miniMAT {
    namespace checker {
        class Checker {
        public:
            Checker(std::shared_ptr<std::map<std::string, double>> id_table,
                    std::shared_ptr<reporter::ErrorReporter> reporter);
            virtual ~Checker() {}

            std::shared_ptr<ast::AST> check(std::shared_ptr<ast::AST> ast);

        private:
            std::shared_ptr<std::map<std::string, double>> id_table;
            std::shared_ptr<reporter::ErrorReporter> reporter;
        };
    }
}

#endif
