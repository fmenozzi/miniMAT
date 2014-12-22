#ifndef MINIMAT_AST_MATRIX_LITERAL_HPP
#define MINIMAT_AST_MATRIX_LITERAL_HPP

#include <string>

#include <miniMAT/ast/Literal.hpp>

namespace miniMAT {
    namespace ast {
        struct MatrixLiteral : public Literal {
            MatrixLiteral(const std::string& spelling, Matrix mat) : Literal(spelling) {
                this->mat = mat;
            }

            std::string GetClassName() const;
            Matrix      GetMatrix() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

            Matrix mat;
        };
    }
}

#endif
