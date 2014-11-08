#ifndef REFERENCE_HPP
#define REFERENCE_HPP

#include <AST.hpp>
#include <Visitors.hpp>

namespace miniMAT {
    namespace ast {
        class Reference : public AST {
        public:
            virtual ~Reference() {}

            virtual std::string GetClassName() const = 0;

            virtual void VisitDisplay(const std::string& prefix) const = 0;
        };
    }
}

#endif
