//
// Created by tomasz on 11.06.16.
//

#include "KeyLexer.h"

std::shared_ptr<Token> KeyLexer::getNextToken() {
    if(!isEOF()){

        switch (currentChar) {
            case (char) TokenType::DOT:
                currentToken = std::make_shared<Token>(TokenType::DOT);
                break;
            case (char) TokenType::LEFT_SQUARE_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::LEFT_SQUARE_BRACKET);
                break;
            case (char) TokenType::RIGHT_SQUARE_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::RIGHT_SQUARE_BRACKET);
                break;
            case (char) TokenType::NUMBER0:
            case (char) TokenType::NUMBER1:
            case (char) TokenType::NUMBER2:
            case (char) TokenType::NUMBER3:
            case (char) TokenType::NUMBER4:
            case (char) TokenType::NUMBER5:
            case (char) TokenType::NUMBER6:
            case (char) TokenType::NUMBER7:
            case (char) TokenType::NUMBER8:
            case (char) TokenType::NUMBER9:
                currentToken = std::make_shared<Token>(TokenType::NUMBER, getNumber());
                return currentToken;
            default:
                currentToken = std::make_shared<Token>(TokenType::TEXT, getText());
                return currentToken;
        }
        getNextChar();
        return currentToken;
    }
    return nullptr;
}

bool KeyLexer::getNextChar() {
    position++;
    currentChar = key[position];
    return !isEOF();
}

std::string KeyLexer::getNumber() {
    std::string number = "";
    number += currentChar;
    while(getNextChar() && isdigit(currentChar)) {
        number += currentChar;
    }
    return number;
}

std::string KeyLexer::getText() {
    std::string text = "";
    text += currentChar;
    while(getNextChar() && !isDot() && !isLeftSquare()) {
        if(isEscapeCharacter()){
            throw std::invalid_argument("Escape character in value token");
        }
        text += currentChar;
    }
    return text;
}

bool KeyLexer::isLeftSquare() const { return currentChar == (char) TokenType::LEFT_SQUARE_BRACKET; }

bool KeyLexer::isEscapeCharacter() const { return currentChar == (char) TokenType::ESCAPE_CHARACTER; }

bool KeyLexer::isDot() const { return currentChar == (char) TokenType::DOT; }

bool KeyLexer::isEOF()const {
    return position == key.size();
}











