cmake_minimum_required(VERSION 3.5)
project(Lexer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Lexer.cpp Lexer.h Token.cpp Token.h TokenType.h JsonParser.cpp JsonParser.h Node.cpp Node.h NodeType.h Pair.cpp Pair.h Value.cpp Value.h Object.cpp Object.h Array.cpp Array.h KeyParser.cpp KeyParser.h JsonConfigLoader.cpp JsonConfigLoader.h Key.cpp Key.h KeyLexer.cpp KeyLexer.h Text.cpp Text.h Number.cpp Number.h)
add_executable(Lexer ${SOURCE_FILES})