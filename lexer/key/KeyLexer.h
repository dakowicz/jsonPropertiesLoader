//
// Created by tomasz on 11.06.16.
//

#ifndef LEXER_KEYLEXER_H
#define LEXER_KEYLEXER_H

#include <string>
#include <memory>
#include <iostream>
#include "../../parser/domain/Key.h"
#include "../domain/Token.h"

class KeyLexer {
public:

    KeyLexer(std::string key) : key(key), position(0), currentChar(key[position]) {}

    bool isEOF()const;

    std::shared_ptr<Token> getNextToken();

private:

    std::string key;

    int position;

    char currentChar;

    std::shared_ptr<Token> currentToken;

    bool getNextChar();

    std::string getNumber();

    std::string getText();

    bool isDot() const;

    bool isEscapeCharacter() const;

    bool isLeftSquare() const;
};


#endif //LEXER_KEYLEXER_H
