#ifndef VISITOR_HPP
#define VISITOR_HPP

namespace miniMAT {
    namespace ast {
        class ScalarType;

        class ExprStmt;

        class UnaryExpr;
        class BinaryExpr;
        class LiteralExpr;

        class FloatLiteral;
        class Operator;

        class Visitor {
        public:
            virtual ~Visitor() {}

            // Types
            virtual void VisitScalarType(ScalarType& st) = 0;

            // Statements
            virtual void VisitExprStmt(ExprStmt& es) = 0;

            // Expressions
            virtual void VisitUnaryExpr(UnaryExpr& ue)     = 0;
            virtual void VisitBinaryExpr(BinaryExpr& be)   = 0;
            virtual void VisitLiteralExpr(LiteralExpr& le) = 0;

            // References

            // Terminals
            virtual void VisitFloatLiteral(FloatLiteral& fl) = 0;
            virtual void VisitOperator(Operator& op)         = 0;
        };
    }
}

#endif
