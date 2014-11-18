#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <AST.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Statement : public AST {
        public:
            virtual ~Statement() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;
        };
    }
}

#endif
