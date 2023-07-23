#include "node.h"

#include <iostream>

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
}

Node::Node(int value, Node* next)
{
    this->value = value;
    this->next = next;
}

Node::~Node()
{
    
}