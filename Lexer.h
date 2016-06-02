//
// Created by tomasz on 23.05.16.
//

#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H


#include <iostream>
#include <fstream>
#include "Token.h"


class Lexer {

public:
    Lexer(const char *fileName);

    ~Lexer();

    Token* getNextToken();

    bool isOpen();

    bool isEOF();

private:

    std::ifstream fileDescriptor;

    void printMessage(const char *message);

    void printErrorMessage(const char *message);

    void printChar(char c);

    int getNumber(char i);

    void skipWhiteSpaces(char &c);

    std::string getText();

    bool isEscapeCharacter(char &nextChar) const;

    bool isQuote(char &nextChar) const;

    void checkWrongCharacter(char nextChar);

    char currentChar;

    void getNextChar(const Token *token);
};


#endif //LEXER_LEXER_H
