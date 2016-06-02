//
// Created by tomasz on 23.05.16.
//

#include "Lexer.h"
#include "TokenType.h"

Lexer::Lexer(const char *fileName) {
    this->fileDescriptor.open(fileName);
    fileDescriptor.get(currentChar);
    if(isOpen()) {
        printMessage("File opened");
    } else {
        printErrorMessage("Unable to open file");
    }
}

Lexer::~Lexer() {

}

Token* Lexer::getNextToken() {
    Token *token = nullptr;

    skipWhiteSpaces(currentChar);
    switch(currentChar) {
        case (char) TokenType::LEFT_CURLY_BRACKET:
            token = new Token(TokenType::LEFT_CURLY_BRACKET);
            break;
        case (char) TokenType::RIGHT_CURLY_BRACKET:
            token = new Token(TokenType::RIGHT_CURLY_BRACKET);
            break;
        case (char) TokenType::COLON:
            token = new Token(TokenType::COLON);
            break;
        case (char) TokenType::SEPARATOR:
            token = new Token(TokenType::SEPARATOR);
            break;
        case (char) TokenType::LEFT_SQUARE_BRACKET:
            token = new Token(TokenType::LEFT_SQUARE_BRACKET);
            break;
        case (char) TokenType::RIGHT_SQUARE_BRACKET:
            token = new Token(TokenType::RIGHT_SQUARE_BRACKET);
            break;
        case (char) TokenType::QUOTE:
            token = new Token(TokenType::TEXT, getText());
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
            token = new Token(TokenType::NUMBER, getNumber(currentChar));
            break;
        default:
            checkWrongCharacter(currentChar);
    }
    getNextChar(token);
    return token;
}

void Lexer::getNextChar(const Token *token) {
    if(token != nullptr) {
        fileDescriptor.get(currentChar);
    }
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
            printMessage("Escape character in text token");
        }
        text += nextChar;
    }
    return text;
}

int Lexer::getNumber(char nextChar) {
    std::string number = "";
    number += nextChar;
    while(fileDescriptor.get(nextChar) && isdigit(nextChar)) {
        number += nextChar;
    }
    return std::stoi(number);
}

void Lexer::skipWhiteSpaces(char &c) {
    while(isspace(c) && !isEOF()){
        fileDescriptor.get(c);
    }
}

bool Lexer::isOpen() {
    return this->fileDescriptor.is_open();
}

void Lexer::printErrorMessage(const char* message) {
    printMessage(message);
    exit(0);
}

void Lexer::printChar(char c) {
    std::cout << c << '\n';
}

void Lexer::printMessage(const char* message) {
    std::cout << message << '\n';
}

bool Lexer::isEOF() {
    return fileDescriptor.eof();
}

bool Lexer::isQuote(char &nextChar) const { return nextChar == (char) TokenType::QUOTE; }

bool Lexer::isEscapeCharacter(char &nextChar) const {
    return nextChar == (char) TokenType::ESCAPE_CHARACTER;
}