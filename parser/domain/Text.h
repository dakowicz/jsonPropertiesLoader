//
// Created by tomasz on 12.06.16.
//

#ifndef LEXER_TEXT_H
#define LEXER_TEXT_H


#include "Node.h"

class Text : public Node{

public:
    Text(const std::string text) : Node(text, NodeType::TEXT) {}
};


#endif //LEXER_TEXT_H
