#ifndef MINIMAT_AST_ID_REF_HPP
#define MINIMAT_AST_ID_REF_HPP

#include <memory>

#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/Identifier.hpp>

namespace miniMAT {
    namespace ast {
        class IdRef : public Reference {
        public:
            IdRef(std::shared_ptr<Identifier> id);
            virtual ~IdRef() {}

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            std::shared_ptr<Identifier> id;
        };
    }
}

#endif
