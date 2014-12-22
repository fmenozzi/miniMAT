#ifndef MINIMAT_AST_TYPE_HPP
#define MINIMAT_AST_TYPE_HPP

#include <miniMAT/ast/AST.hpp>
#include <miniMAT/ast/TypeKind.hpp>
#include <miniMAT/visit/Visitors.hpp>

namespace miniMAT {
    namespace ast {
        struct Type : public AST {
            Type(TypeKind kind);
            virtual ~Type() {}

            TypeKind GetKind() const;

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
            virtual Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) = 0;
            virtual void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                    std::shared_ptr<reporter::ErrorReporter> reporter) const = 0;

        private:
            TypeKind kind;
        };
    }
}

#endif
