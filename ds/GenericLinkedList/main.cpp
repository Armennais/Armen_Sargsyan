
#include <iostream>
#include "linkedlist.h"
#include "linkedlist.cpp"
using namespace std;

int main()
{
    try
    {
        List<int> list;
        int num;
        srand(time(0));
        for (int i = 0; i < 20; i++)
        {
            num = rand() % 10 + 1;
            list.Add(num);
        }
        cout << "Print List Elements:\n";
        cout << list;

        cout << list.getElement(55);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << '\n';
    }

    // list.AddAt(4,2);
    // list.removeAt(2);
    // cout << list.GetCount() << endl;
    // cout << list.getElement(3) << endl;
    // list.removeAll();
}
