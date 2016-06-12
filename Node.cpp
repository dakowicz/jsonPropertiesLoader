//
// Created by tomasz on 05.06.16.
//

#include "Node.h"

std::vector<std::shared_ptr<Node>> Node::getChildren() {
    return children;
}

std::shared_ptr<Node> Node::getChildren(int index) {
    return children[index];
}

bool Node::isVisited() {
    return visited;
}

void Node::setVisited(bool value) {
    visited = value;
}













