#ifndef TYPE_HPP
#define TYPE_HPP

#include <AST.hpp>
#include <TypeKind.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Type : public AST {
        public:
            Type(TypeKind kind);
            virtual ~Type() {}

            TypeKind GetKind() const;

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual double VisitEvaluate(std::shared_ptr<std::map<std::string, double>> id_table) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, double>> id_table,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;

        private:
            TypeKind kind;
        };
    }
}

#endif
