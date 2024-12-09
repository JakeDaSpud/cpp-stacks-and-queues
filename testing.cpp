#include "SLinkedList.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    SLinkedList<int> sll;

    sll.push_back(4);
    sll.push_back(560);
    sll.push_back(8);

    sll.print();

    return 0;
}
