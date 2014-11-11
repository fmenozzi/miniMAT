#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

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
            double VisitEvaluate() const;
            void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;
        };
    }
}

#endif
