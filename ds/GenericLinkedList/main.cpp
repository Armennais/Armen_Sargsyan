
#include <iostream>
#include "linkedlist.h"
#include "linkedlist.cpp"
using namespace std;

int main() {
    List<int> list;
    int num;
    srand(time(0));
    for(int i = 0;i < 20; i++)
    {
        num = rand() % 10 + 1;
        list.Add(num);
    }
    cout << "Print List Elements:\n";
    list.printList(list);


    // list.AddAt(4,2);
    // list.printList(list);
    // list.removeAt(2);
    // list.printList(list);
    // cout << list.GetCount() << endl;
    // list.printList(list);
    // cout << list.getElement(3) << endl;
    // list.printList(list);
    // list.removeAll();
    // list.printList(list);

}