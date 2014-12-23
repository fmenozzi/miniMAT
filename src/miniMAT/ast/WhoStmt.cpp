#include <miniMAT/ast/WhoStmt.hpp>

#include <iostream>

namespace miniMAT {
    namespace ast {
        std::string WhoStmt::GetClassName() const {
            return "WhoStmt";
        }

        void WhoStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
        }

        Matrix WhoStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, Matrix>> vars) {
            if (vars->size() != 0) {
                std::cout  << std::endl;
                for (auto var : *vars)
                    std::cout << var.first << std::endl;
                std::cout  << std::endl;
            }

            return Matrix::Zero(0,0);
        }

        void WhoStmt::VisitCheck(std::shared_ptr<std::map<std::string, Matrix>> vars,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
    }
}