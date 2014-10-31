#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <ScalarType.hpp>

#include <ExprStmt.hpp>

#include <UnaryExpr.hpp>
#include <BinaryExpr.hpp>
#include <LiteralExpr.hpp>

#include <FloatLiteral.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        template<typename ArgType, typename ResultType>
        class Visitor {
        public:
            virtual ~Visitor() {}

            // Types
            virtual ResultType VisitScalarType(const ScalarType& st, ArgType arg) = 0;

            // Statements
            virtual ResultType VisitExprStmt(const ExprStmt& es, ArgType arg) = 0;

            // Expressions
            virtual ResultType VisitUnaryExpr(const UnaryExpr& ue, ArgType arg) = 0;
            virtual ResultType VisitBinaryExpr(const BinaryExpr& be, ArgType arg) = 0;
            virtual ResultType VisitLiteralExpr(const LiteralExpr& le, ArgType arg) = 0;

            // References

            // Terminals
            virtual ResultType VisitFloatLiteral(const FloatLiteral& fl, ArgType arg) = 0;
            virtual ResultType VisitOperator(const Operator& op, ArgType arg) = 0;
        };
    }
}

#endif
