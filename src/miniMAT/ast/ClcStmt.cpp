#include <miniMAT/ast/ClcStmt.hpp>

#include <iostream>
#include <cstdlib>

namespace miniMAT {
    namespace ast {
        std::string ClcStmt::ClassName() const {
            return "ClcStmt";
        }

        void ClcStmt::VisitDisplay(const std::string& prefix) const {
            using namespace miniMAT::visit::display;

            Show(prefix, *this);
        }

        ast::Matrix ClcStmt::VisitEvaluate(std::shared_ptr<std::map<std::string, ast::Matrix>> vars) {
        #ifdef _WIN32
            auto clearstr = "cls";
        #elif __APPLE__
            auto clearstr = "clear";
        #elif __linux
            auto clearstr = "clear";
        #endif

            int i __attribute__((unused));  // I hate warnings
            if (std::system(nullptr))
                i = std::system(clearstr); 
            else
                std::cout << "Could not clear screen, for some reason" << std::endl;

            return ast::Matrix::Zero(0,0);
        }

        void ClcStmt::VisitCheck(std::shared_ptr<std::map<std::string, ast::Matrix>> vars,
                                 std::shared_ptr<reporter::ErrorReporter> reporter) const {
     
        }
    }
}