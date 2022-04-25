#include "queue.hpp"
#include "../GenericLinkedList/linkedlist.cpp"
#include <iostream>
using namespace std;
int main()
{
    Queue<int> queue;
    queue.push(12);
    cout << queue.pop() << endl;
}