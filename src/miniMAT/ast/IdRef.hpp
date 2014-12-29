#ifndef MINIMAT_AST_ID_REF_HPP
#define MINIMAT_AST_ID_REF_HPP

#include <memory>

#include <miniMAT/ast/Reference.hpp>
#include <miniMAT/ast/Identifier.hpp>

namespace miniMAT {
    namespace ast {
        struct IdRef : public Reference {
            IdRef(std::shared_ptr<Identifier> id);

            std::string ClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            std::shared_ptr<Identifier> id;
        };
    }
}

#endif
