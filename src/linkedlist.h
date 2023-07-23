#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList
{
public:
    static void listMerge(LinkedList* l1, LinkedList* l2);

    LinkedList();
    ~LinkedList();

    Node* getStartNode();
    Node* getEndNode();
    void append(int value);
    void removeLast();
    int getLength() const;
    int& getElementAt(const int idx);
    void removeAt(const int idx);
    void insertAt(const int idx, int value);
    int& operator[](const int idx);
    void operator+=(LinkedList* l2);
    
    void listMerge(LinkedList* l2);

private:
    Node* startNode;
    Node* endNode;
    int length;
};


#endif