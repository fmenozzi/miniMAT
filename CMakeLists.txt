cmake_minimum_required(VERSION 2.6)

project(miniMAT)

# C++11, all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Check for Eigen
#find_package(Eigen3 REQUIRED)
#include_directories(${EIGEN3_INCLUDE_DIR})

include_directories(src/miniMAT/ast)
include_directories(src/miniMAT/checker)
include_directories(src/miniMAT/lexer)
include_directories(src/miniMAT/parser)
include_directories(src/miniMAT/reporter)
include_directories(src/miniMAT/visit)

set(SOURCES src/miniMAT/miniMAT.cpp

            src/miniMAT/ast/AssignStmt.cpp
            src/miniMAT/ast/BinaryExpr.cpp
            src/miniMAT/ast/ExprStmt.cpp
            src/miniMAT/ast/FloatLiteral.cpp
            src/miniMAT/ast/Identifier.cpp
            src/miniMAT/ast/IdRef.cpp
            src/miniMAT/ast/LiteralExpr.cpp
            src/miniMAT/ast/Operator.cpp
            src/miniMAT/ast/RefExpr.cpp
            src/miniMAT/ast/ScalarType.cpp
            src/miniMAT/ast/Terminal.cpp
            src/miniMAT/ast/Type.cpp
            src/miniMAT/ast/UnaryExpr.cpp

            src/miniMAT/checker/Checker.cpp

            src/miniMAT/lexer/Lexer.cpp
            src/miniMAT/lexer/Token.cpp
            src/miniMAT/lexer/TokenKind.cpp

            src/miniMAT/parser/Parser.cpp

            src/miniMAT/reporter/ErrorReporter.cpp

            src/miniMAT/visit/Visitors.cpp
    )

add_executable(miniMAT ${SOURCES})
