//
// Created by tomasz on 23.05.16.
//

#ifndef LEXER_TOKENTYPE_H
#define LEXER_TOKENTYPE_H


enum class TokenType {
    LEFT_CURLY_BRACKET = '{',
    RIGHT_CURLY_BRACKET = '}',
    COLON = ':',
    SEPARATOR = ',',
    LEFT_SQUARE_BRACKET = '[',
    RIGHT_SQUARE_BRACKET = ']',

    NUMBER0 = '0',
    NUMBER1 = '1',
    NUMBER2 = '2',
    NUMBER3 = '3',
    NUMBER4 = '4',
    NUMBER5 = '5',
    NUMBER6 = '6',
    NUMBER7 = '7',
    NUMBER8 = '8',
    NUMBER9 = '9',
    NUMBER,

    QUOTE = '"',
    ESCAPE_CHARACTER = '\\',
    TEXT
};


#endif //LEXER_TOKENTYPE_H
