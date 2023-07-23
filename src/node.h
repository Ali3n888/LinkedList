#ifndef NODE_H
#define NODE_H

struct Node
{
    int value;
    Node* next;
    
    Node(int value=0);
    Node(int value, Node* next);
    ~Node();
};

#endif