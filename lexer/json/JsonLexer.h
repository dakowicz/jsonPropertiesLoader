//
// Created by tomasz on 23.05.16.
//

#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include <iostream>
#include <memory>
#include <fstream>
#include "../domain/Token.h"

class JsonLexer {

public:

    JsonLexer(std::string fileName);

    ~JsonLexer();

    std::shared_ptr<Token> getNextToken();

    bool isOpen();

    bool isEOF()const;

private:

    std::ifstream fileDescriptor;

    std::shared_ptr<Token> currentToken;

    void printMessage(std::string message);

    std::string getNumber();

    std::string getText();

    bool isEscapeCharacter(char &nextChar) const;

    bool isQuote(char &nextChar) const;

    void checkWrongCharacter(char nextChar);

    char currentChar;

    void getNextChar(std::shared_ptr<Token> token);

    void skipWhiteSpaces();

    void printErrorMessage(std::string message);
};


#endif //LEXER_LEXER_H
