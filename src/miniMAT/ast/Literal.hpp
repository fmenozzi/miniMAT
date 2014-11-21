#ifndef LITERAL_HPP
#define LITERAL_HPP

#include <string>

#include <Terminal.hpp>

namespace miniMAT {
    namespace ast {
        class Literal : public Terminal {
        public:
            Literal(const std::string& spelling) : Terminal(spelling) {}
            virtual ~Literal() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
