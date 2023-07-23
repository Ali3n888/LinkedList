#include "linkedlist.h"
#include <iostream>
#include <stdexcept>

LinkedList::LinkedList()
{
    this->endNode = new Node(0);
    this->startNode = new Node(0, this->endNode);
    this->length = 0;
}

LinkedList::~LinkedList()
{
    while(this->startNode->next->next != nullptr)
    {
        this->removeLast();
    }
    delete startNode;
    delete endNode;
}

Node* LinkedList::getStartNode()
{
    return startNode;
}

Node* LinkedList::getEndNode()
{
    return endNode;
}

int LinkedList::getLength() const
{
    return length;
}

void LinkedList::append(int value)
{
    if(this->length == 0)
    {
        startNode->next = new Node(value, this->endNode);
    }
    else
    {
        Node* tmp = this->startNode->next;
        while(tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(value, this->endNode);
    }
    length ++;
}

void LinkedList::removeLast()
{
    if(this->length == 0)
    {
        throw std::length_error("The list has the length 0.");
    }
    else
    {
        Node* tmp1 = this->startNode->next;
        Node* tmp2 = this->startNode;
        while(tmp1->next->next != nullptr)
        {
            tmp1 = tmp1->next; 
            tmp2 = tmp2->next;
        }
        tmp2->next = this->endNode;
        delete tmp1;  
    }
    length--;
}

int& LinkedList::getElementAt(int idx)
{
    Node* tmp = nullptr;
    if (idx < this->length)
    {
        tmp = this->startNode->next;
        for(int i = 0; i < idx; i++)
        {
            tmp = tmp->next;
        }
    }
    else 
    {
        throw std::out_of_range("The index is out of range of the list.");
    }
    return tmp->value;
}

int& LinkedList::operator[](const int idx)
{
    return this->getElementAt(idx);
}

void LinkedList::removeAt(int idx)
{
    if(this->length < idx)
    {
        Node* tmp1 = this->startNode;
        Node* tmp2 = this->startNode->next;
        for(int i = 0; i < idx; i++)
        {
            tmp1 = tmp1->next; 
            tmp2 = tmp2->next;
        }
        tmp1->next = tmp2->next;
        delete tmp2;  
        length --;
    }
    else
    {
        throw std::out_of_range("The index is out of range of the list.");
    }
}

void LinkedList::insertAt(int idx, int value)
{
    if(this->length < idx)
    {
        Node* tmp = this->startNode->next;
        for(int i = 0; i < idx; i++)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(value, tmp->next);
        length ++;
    }
    else
    {
        throw std::out_of_range("The index is out of range of the list.");
    }
}

void LinkedList::listMerge(LinkedList* l2)
{
    listMerge(this, l2);
}

void LinkedList::listMerge(LinkedList* l1, LinkedList* l2)
{
    Node* tmp = l2->startNode->next;
    while(tmp->next != nullptr)
    {
        l1->append(tmp->value);
    }
}

void LinkedList::operator+=(LinkedList* l2)
{
    listMerge(this, l2);
}