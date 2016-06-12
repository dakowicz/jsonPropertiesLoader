//
// Created by tomasz on 09.06.16.
//

#ifndef LEXER_OBJECT_H
#define LEXER_OBJECT_H


#include "Node.h"

class Object : public Node{

public:
    Object(std::vector<std::shared_ptr<Node>>  members) : Node("", NodeType::OBJECT, members) { }
};


#endif //LEXER_OBJECT_H
