#ifndef VISITOR_HPP
#define VISITOR_HPP

class ScalarType;

class ExprStmt;

class UnaryExpr;
class BinaryExpr;
class LiteralExpr;

class FloatLiteral;
class Operator;

namespace miniMAT {
    namespace ast {
        class Visitor {
        public:
            virtual ~Visitor() {}

            // Types
            virtual void VisitScalarType(const ScalarType& st) = 0;

            // Statements
            virtual void VisitExprStmt(const ExprStmt& es) = 0;

            // Expressions
            virtual void VisitUnaryExpr(const UnaryExpr& ue)     = 0;
            virtual void VisitBinaryExpr(const BinaryExpr& be)   = 0;
            virtual void VisitLiteralExpr(const LiteralExpr& le) = 0;

            // References

            // Terminals
            virtual void VisitFloatLiteral(const FloatLiteral& fl) = 0;
            virtual void VisitOperator(const Operator& op)         = 0;
        };
    }
}

#endif
