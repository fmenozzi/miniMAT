CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(miniMAT)

# C++11, all warnings
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Check for Eigen
SET(EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}")
IF (NOT EIGEN3_INCLUDE_DIR)
    MESSAGE(FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
ENDIF()
INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR})


INCLUDE_DIRECTORIES(src/miniMAT/ast)
INCLUDE_DIRECTORIES(src/miniMAT/checker)
INCLUDE_DIRECTORIES(src/miniMAT/lexer)
INCLUDE_DIRECTORIES(src/miniMAT/parser)
INCLUDE_DIRECTORIES(src/miniMAT/reporter)
INCLUDE_DIRECTORIES(src/miniMAT/visit)

SET(SOURCES src/miniMAT/miniMAT.cpp

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

ADD_EXECUTABLE(miniMAT ${SOURCES})
