cmake_minimum_required(VERSION 3.5)
project(JsonLexer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp lexer/json/JsonLexer.cpp lexer/json/JsonLexer.h lexer/domain/Token.cpp lexer/domain/Token.h lexer/domain/TokenType.h parser/json/JsonParser.cpp parser/json/JsonParser.h parser/domain/Node.h parser/domain/NodeType.h parser/domain/Pair.h parser/domain/Object.h parser/domain/Array.h parser/key/KeyParser.cpp parser/key/KeyParser.h configLoader/JsonConfigLoader.cpp configLoader/JsonConfigLoader.h parser/domain/Key.h lexer/key/KeyLexer.cpp lexer/key/KeyLexer.h parser/domain/Text.h parser/domain/Number.h)
add_executable(JsonLexer ${SOURCE_FILES})