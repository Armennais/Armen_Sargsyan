#include "deque.hpp"
#include "../GenericLinkedList/linkedlist.cpp"
#include <iostream>
using namespace std;
int main()
{
    Deque<int> deque;
    deque.pushBack(5);
    cout << deque.lastData() << endl;
}