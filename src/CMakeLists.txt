cmake_minimum_required(VERSION 2.6)

project(miniMAT)

# C++11, all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Check for Eigen
#find_package(Eigen3 REQUIRED)
#include_directories(${EIGEN3_INCLUDE_DIR})

include_directories(miniMAT/lexer)
include_directories(miniMAT/parser)
include_directories(miniMAT/ast)

set(SOURCES miniMAT/miniMAT.cpp

			miniMAT/lexer/Lexer.cpp
			miniMAT/lexer/Token.cpp
			miniMAT/lexer/TokenKind.cpp

			miniMAT/parser/Parser.cpp

			miniMAT/ast/BinaryExpr.cpp
			miniMAT/ast/ExprStmt.cpp
			miniMAT/ast/FloatLiteral.cpp
			miniMAT/ast/LiteralExpr.cpp
			miniMAT/ast/Operator.cpp
			miniMAT/ast/ScalarType.cpp
			miniMAT/ast/Terminal.cpp
			miniMAT/ast/Type.cpp
			miniMAT/ast/UnaryExpr.cpp
	)

add_executable(miniMAT ${SOURCES})
