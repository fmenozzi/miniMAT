#ifndef MINIMAT_AST_IDENTIFIER_HPP
#define MINIMAT_AST_IDENTIFIER_HPP

#include <string>

#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        class Identifier : public Terminal {
        public:
            Identifier(const std::string& spelling) : Terminal(spelling) {}
            virtual ~Identifier() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;
        };
    }
}

#endif
