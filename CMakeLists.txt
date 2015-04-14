CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(miniMAT)

# C++11, all warnings
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Eigen
INCLUDE_DIRECTORIES(libs/Eigen)

INCLUDE_DIRECTORIES(src)
SET(SOURCES src/miniMAT/miniMAT.cpp

            src/miniMAT/ast/AssignStmt.cpp
            src/miniMAT/ast/BinaryExpr.cpp
            src/miniMAT/ast/CallExpr.cpp
            src/miniMAT/ast/ClcStmt.cpp
            src/miniMAT/ast/ClearStmt.cpp
            src/miniMAT/ast/ExprStmt.cpp
            src/miniMAT/ast/Identifier.cpp
            src/miniMAT/ast/IdRef.cpp
            src/miniMAT/ast/LiteralExpr.cpp
            src/miniMAT/ast/MatrixLiteral.cpp
            src/miniMAT/ast/Operator.cpp
            src/miniMAT/ast/RefExpr.cpp
            src/miniMAT/ast/Terminal.cpp
            src/miniMAT/ast/UnaryExpr.cpp
            src/miniMAT/ast/WhoStmt.cpp
            src/miniMAT/ast/WhosStmt.cpp

            src/miniMAT/checker/Checker.cpp

            src/miniMAT/lexer/Lexer.cpp
            src/miniMAT/lexer/Token.cpp
            src/miniMAT/lexer/TokenKind.cpp

            src/miniMAT/parser/Parser.cpp

            src/miniMAT/reporter/ErrorReporter.cpp

            src/miniMAT/util/Dims.cpp
            src/miniMAT/util/NumDigits.cpp
            src/miniMAT/util/PrintResult.cpp

            src/miniMAT/visit/Visitors.cpp
    )

ADD_EXECUTABLE(miniMAT ${SOURCES})
