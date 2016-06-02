cmake_minimum_required(VERSION 3.5)
project(Lexer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Lexer.cpp Lexer.h Token.cpp Token.h TokenType.h Parser.cpp Parser.h)
add_executable(Lexer ${SOURCE_FILES})