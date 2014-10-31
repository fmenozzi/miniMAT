#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <memory>

#include <ScalarType.hpp>

#include <ExprStmt.hpp>

#include <UnaryExpr.hpp>
#include <BinaryExpr.hpp>
#include <LiteralExpr.hpp>

#include <FloatLiteral.hpp>
#include <Operator.hpp>

namespace miniMAT {
    namespace ast {
        using std::unique_ptr;

        template<typename ArgType, typename ResultType>
        class Visitor {
        public:
            virtual ~Visitor() {}

            // Types
            virtual ResultType VisitScalarType(const unique_ptr<ScalarType>& st,
                                        ArgType arg) = 0;

            // Statements
            virtual ResultType VisitExprStmt(const unique_ptr<ExprStmt>& es,
                                        ArgType arg) = 0;

            // Expressions
            virtual ResultType VisitUnaryExpr(const unique_ptr<UnaryExpr>& ue,
                                        ArgType arg) = 0;
            virtual ResultType VisitBinaryExpr(const unique_ptr<BinaryExpr>& be,
                                        ArgType arg) = 0;
            virtual ResultType VisitLiteralExpr(const unique_ptr<LiteralExpr>& le,
                                        ArgType arg) = 0;

            // References

            // Terminals
            virtual ResultType VisitFloatLiteral(const unique_ptr<FloatLiteral>& fl,
                                        ArgType arg) = 0;
            virtual ResultType VisitOperator(const unique_ptr<Operator>& op,
                                        ArgType arg) = 0;
        };
    }
}

#endif
