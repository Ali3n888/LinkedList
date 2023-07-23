#include <iostream>
#include <memory>

#include "linkedlist.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World" << std::endl;
    std::shared_ptr<LinkedList> list(new LinkedList());
    list->append(5);
    list->append(8);
    
    std::cout << list->getLength() << std::endl;
    // auto tmp = list->getStartNode()->next;
    // std::cout << list->getEndNode() << std::endl;
    // std::cout << list->getStartNode()->next << std::endl;
    // std::cout << tmp << std::endl;
    // std::cout << tmp->next<< std::endl;
    
    // std::cout << &tmp->next->next->next->next << std::endl;
    // std::cout << list->getEndNode() << std::endl;
    // do
    // {
    //     std::cout << tmp->value << std::endl;
    //     std::cout << tmp->next << std::endl;
    //     tmp = tmp->next;
    // }
    // while(tmp->next != nullptr);

    try
    { 
        std::cout << list->getElementAt(0) << std::endl;
        std::cout << (*list)[1] << std::endl;
        std::cout << (*list)[7] << std::endl;
    }
    catch(std::out_of_range e)
    {
        std::cerr << "Out of Bounds Error" << std::endl;
    }
    // list->removeLast();
    // tmp = list->getStartNode()->next;
    // do
    // {
    //     std::cout << tmp->value << std::endl;
    //     std::cout << tmp->next << std::endl;
    //     tmp = tmp->next;
    // }
    // while(tmp->next != nullptr);
    
}