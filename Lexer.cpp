//
// Created by tomasz on 23.05.16.
//

#include "Lexer.h"
#include "TokenType.h"

Lexer::Lexer(std::string fileName) {
    this->fileDescriptor.open(fileName);
    fileDescriptor.get(currentChar);
    if(isOpen()) {
        printMessage("File opened");
    } else {
        printErrorMessage("Unable to open file");
    }
}

Lexer::~Lexer() {
    fileDescriptor.close();
}

std::shared_ptr<Token> Lexer::getNextToken() {
    if(!isEOF()) {

        skipWhiteSpaces();
        switch (currentChar) {
            case (char) TokenType::LEFT_CURLY_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::LEFT_CURLY_BRACKET);
                break;
            case (char) TokenType::RIGHT_CURLY_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::RIGHT_CURLY_BRACKET);
                break;
            case (char) TokenType::COLON:
                currentToken = std::make_shared<Token>(TokenType::COLON);
                break;
            case (char) TokenType::SEPARATOR:
                currentToken = std::make_shared<Token>(TokenType::SEPARATOR);
                break;
            case (char) TokenType::LEFT_SQUARE_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::LEFT_SQUARE_BRACKET);
                break;
            case (char) TokenType::RIGHT_SQUARE_BRACKET:
                currentToken = std::make_shared<Token>(TokenType::RIGHT_SQUARE_BRACKET);
                break;
            case (char) TokenType::QUOTE:
                currentToken = std::make_shared<Token>(TokenType::TEXT, getText());
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
            case (char) TokenType::MINUS:
                currentToken = std::make_shared<Token>(TokenType::NUMBER, getNumber());
                return currentToken;
            default:
                checkWrongCharacter(currentChar);
        }
        getNextChar(currentToken);
    }
    return currentToken;
}

void Lexer::getNextChar(std::shared_ptr<Token> token) {
    fileDescriptor.get(currentChar);
}

void Lexer::checkWrongCharacter(char nextChar) {
    if(isEOF()) {
        printMessage("The file has been processed completely");
    } else {
        printErrorMessage("Wrong character: " + nextChar);
    }
}

std::string Lexer::getText() {
    char nextChar;
    std::string text = "";

    while(fileDescriptor.get(nextChar) && !isQuote(nextChar)) {
        if(isEscapeCharacter(nextChar)){
            throw std::invalid_argument("Escape character in value token");
        }
        text += nextChar;
    }
    return text;
}

std::string Lexer::getNumber() {
    std::string number = "";
    number += currentChar;
    while(fileDescriptor.get(currentChar) && isdigit(currentChar)) {
        number += currentChar;
    }
    return number;
}

void Lexer::skipWhiteSpaces() {
    while(isspace(currentChar) && !isEOF()){
        fileDescriptor.get(currentChar);
    }
}

bool Lexer::isOpen() {
    return this->fileDescriptor.is_open();
}

void Lexer::printErrorMessage(std::string message) {
    printMessage(message);
    exit(0);
}

void Lexer::printMessage(std::string message) {
    std::cout << message << '\n';
}

bool Lexer::isEOF()const {
    return fileDescriptor.eof();
}

bool Lexer::isQuote(char &nextChar) const { return nextChar == (char) TokenType::QUOTE; }

bool Lexer::isEscapeCharacter(char &nextChar) const {
    return nextChar == (char) TokenType::ESCAPE_CHARACTER;
}



