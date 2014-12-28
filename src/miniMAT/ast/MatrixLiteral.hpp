#ifndef MINIMAT_AST_MATRIX_LITERAL_HPP
#define MINIMAT_AST_MATRIX_LITERAL_HPP

#include <string>

#include <miniMAT/ast/Literal.hpp>

namespace miniMAT {
    namespace ast {
        struct MatrixLiteral : public Literal {
            MatrixLiteral(const std::string& spelling, ast::Matrix mat) : Literal(spelling) {
                this->mat = mat;
            }

            std::string GetClassName() const;
            ast::Matrix      GetMatrix() const;

            void VisitDisplay(const std::string& prefix) const;
            ast::Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            ast::Matrix mat;
        };
    }
}

#endif
