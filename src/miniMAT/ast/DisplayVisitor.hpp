#ifndef DISPLAY_VISITOR_HPP
#define DISPLAY_VISITOR_HPP

#include <string>

namespace miniMAT {
    namespace ast {
        class ScalarType;

        class ExprStmt;

        class UnaryExpr;
        class BinaryExpr;
        class LiteralExpr;

        class FloatLiteral;
        class Operator;

        class DisplayVisitor {
        public:
            virtual ~DisplayVisitor() {}

            // Types
            virtual void VisitScalarType(ScalarType& st, const std::string& prefix) = 0;

            // Statements
            virtual void VisitExprStmt(ExprStmt& es, const std::string& prefix) = 0;

            // Expressions
            virtual void VisitUnaryExpr(UnaryExpr& ue, const std::string& prefix)     = 0;
            virtual void VisitBinaryExpr(BinaryExpr& be, const std::string& prefix)   = 0;
            virtual void VisitLiteralExpr(LiteralExpr& le, const std::string& prefix) = 0;

            // References

            // Terminals
            virtual void VisitFloatLiteral(FloatLiteral& fl, const std::string& prefix) = 0;
            virtual void VisitOperator(Operator& op, const std::string& prefix)         = 0;
        };
    }
}

#endif
