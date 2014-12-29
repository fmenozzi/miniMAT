#include <miniMAT/visit/Visitors.hpp>
#include <iostream>

namespace miniMAT {
    namespace visit {
        namespace display {
            void ShowTree(const ast::AST& ast) {
                std::cout << "================ AST Display ================" << std::endl;
                ast.VisitDisplay("");
                std::cout << "=============================================" << std::endl;
            }

            void Show(const std::string& prefix, const std::string& text) {
                std::cout << prefix << text << std::endl;
            }

            void Show(const std::string& prefix, const ast::AST& ast) {
                std::cout << prefix << ast.ClassName() << std::endl;
            }

            std::string Quote(const std::string& text) {
                return "\"" + text + "\"";
            }

            std::string Indent(const std::string& prefix) {
                return prefix + "   ";
            }
        }

        namespace evaluate {

        }
    }
}
