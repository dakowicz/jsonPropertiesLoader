//
// Created by tomasz on 09.06.16.
//

#ifndef LEXER_ARRAY_H
#define LEXER_ARRAY_H


#include "Node.h"

class Array : public Node{

public:
    Array(const std::vector<std::shared_ptr<Node>> elements) : Node("", NodeType::ARRAY, elements) { }
};


#endif //LEXER_ARRAY_H
