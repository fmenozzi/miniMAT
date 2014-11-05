#include <ASTDisplay.hpp>
#include <iostream>

namespace miniMAT {
    namespace ast {
        void ASTDisplay::ShowTree(AST& ast) {
            std::cout << "======= AST Display =======================" << std::endl;
            ast.visit(*this, "");
            std::cout << "===========================================" << std::endl;
        }
    }
}
