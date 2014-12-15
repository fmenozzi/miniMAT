#ifndef MINIMAT_VISIT_VISITORS_HPP
#define MINIMAT_VISIT_VISITORS_HPP

#include <miniMAT/ast/AST.hpp>

namespace miniMAT {
    namespace visit {
        namespace display {
            void ShowTree(const ast::AST& ast);

            void Show(const std::string& prefix, const std::string& text);
            void Show(const std::string& prefix, const ast::AST& ast);

            std::string Quote(const std::string& text);
            std::string Indent(const std::string& text);
        }

        namespace evaluate {

        }
    }
}

#endif
