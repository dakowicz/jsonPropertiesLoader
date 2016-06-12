//
// Created by tomasz on 12.06.16.
//

#ifndef LEXER_NUMBER_H
#define LEXER_NUMBER_H


#include "Node.h"

class Number : public Node{

public:
    Number(const std::string number) : Node(number, NodeType::NUMBER) {}
};


#endif //LEXER_NUMBER_H
