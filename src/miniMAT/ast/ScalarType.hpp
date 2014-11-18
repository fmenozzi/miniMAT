#ifndef SCALAR_TYPE_HPP
#define SCALAR_TYPE_HPP

#include <Type.hpp>
#include <TypeKind.hpp>

namespace miniMAT {
    namespace ast {
        class ScalarType : public Type {
        public:
            ScalarType(TypeKind kind) : Type(kind) {}

            virtual ~ScalarType() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        private:
            TypeKind kind;
        };
    }
}

#endif
