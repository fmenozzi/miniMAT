#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <AST.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Terminal : public AST {
        public:
            Terminal(const std::string& spelling);
            virtual ~Terminal() {}

            std::string GetSpelling() const;

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;

        private:
            std::string spelling;
        };
    }
}

#endif
