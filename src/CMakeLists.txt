cmake_minimum_required(VERSION 2.6)

project(miniMAT)

# C++11, all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Check for Eigen
#find_package(Eigen3 REQUIRED)
#include_directories(${EIGEN3_INCLUDE_DIR})

include_directories(miniMAT/lexer)

set(SOURCES miniMAT/miniMAT.cpp

			miniMAT/lexer/Lexer.cpp
			miniMAT/lexer/Token.cpp
			miniMAT/lexer/TokenKind.cpp
	)

add_executable(miniMAT ${SOURCES})
