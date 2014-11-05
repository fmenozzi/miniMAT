#ifndef AST_DISPLAY_HPP
#define AST_DISPLAY_HPP

#include <string>

#include <DisplayVisitor.hpp>
#include <AST.hpp>

namespace miniMAT {
    namespace ast {
        class ASTDisplay : public DisplayVisitor {
        public:
            void ShowTree(AST& ast);
            void Show(const std::string& prefix, const std::string& text);
            void Show(const std::string& prefix, const AST& node);
            std::string Quote(const std::string& text);

            // Types
            void VisitScalarType(ScalarType& st, const std::string& prefix);

            // Statements
            void VisitExprStmt(ExprStmt& es, const std::string& prefix);

            // Expressions
            void VisitUnaryExpr(UnaryExpr& ue, const std::string& prefix);
            void VisitBinaryExpr(BinaryExpr& be, const std::string& prefix);
            void VisitLiteralExpr(LiteralExpr& le, const std::string& prefix);

            // References

            // Terminals
            void VisitFloatLiteral(FloatLiteral& fl, const std::string& prefix);
            void VisitOperator(Operator& op, const std::string& prefix);
        };
    }
}

#endif
