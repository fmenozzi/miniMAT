#include <ASTDisplay.hpp>
#include <iostream>

namespace miniMAT {
    namespace ast {
        void ASTDisplay::ShowTree(AST& ast) {
            std::cout << "======= AST Display =======================" << std::endl;
            ast.visit(*this, "");
            std::cout << "===========================================" << std::endl;
        }

        void ASTDisplay::Show(const std::string& prefix, const std::string& text) {
            std::cout << prefix << text << std::endl;
        }

        void ASTDisplay::Show(const std::string& prefix, const AST& node) {
            std::cout << prefix << node.GetClassName() << std::endl;
        }

        std::string ASTDisplay::Quote(const std::string& text) {
            return "\"" + text + "\"";
        }
    }
}
