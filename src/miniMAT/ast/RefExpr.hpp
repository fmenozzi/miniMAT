#ifndef REF_EXPR_HPP
#define REF_EXPR_HPP

#include <memory>

#include <Expression.hpp>
#include <Reference.hpp>

namespace miniMAT {
    namespace ast {
        class RefExpr : public Expression {
        public:
            RefExpr(std::shared_ptr<Reference> ref);
            virtual ~RefExpr() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;

        //private:
            std::shared_ptr<Reference> ref;
        };
    }
}

#endif
