cmake_minimum_required(VERSION 3.0)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/include)
set(SOURCE_FILES
        ASTNodes.h
        grammar.cpp
        grammar.hpp
        grammar.y
        Makefile
        test.input
        token.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
