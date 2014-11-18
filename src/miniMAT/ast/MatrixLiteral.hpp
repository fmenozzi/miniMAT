#ifndef MATRIX_LITERAL_HPP
#define MATRIX_LITERAL_HPP

#include <string>

#include <Literal.hpp>

namespace miniMAT {
    namespace ast {
        class MatrixLiteral : public Literal {
        public:
            MatrixLiteral(const std::string& spelling, Matrix mat) : Literal(spelling) {
                this->mat = mat;
            }

            std::string GetClassName() const;

            void VisitDisplay(const std::string& prefix) const;
            Matrix VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> id_table);
            void VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> id_table,
                            std::shared_ptr<reporter::ErrorReporter> reporter) const;

        //private:
            Matrix mat;
        };
    }
}

#endif
