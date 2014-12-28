#ifndef MINIMAT_CHECKER_CHECKER_HPP
#define MINIMAT_CHECKER_CHECKER_HPP

#include <map>
#include <string>
#include <memory>

#include <miniMAT/ast/AST.hpp>
#include <miniMAT/reporter/ErrorReporter.hpp>

namespace miniMAT {
    namespace checker {
        class Checker {
        public:            
            Checker(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                    std::shared_ptr<reporter::ErrorReporter> reporter);
            virtual ~Checker() {}

            std::shared_ptr<ast::AST> check(std::shared_ptr<ast::AST> ast);

        private:
            std::shared_ptr<std::map<std::string, ast::Matrix>> vars;
            std::shared_ptr<reporter::ErrorReporter> reporter;
        };
    }
}

#endif
