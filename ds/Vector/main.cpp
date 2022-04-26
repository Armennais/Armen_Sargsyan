#include "vector.hpp"

int main ()
{
    MyVector<int> vector;
    for (int i = 0; i < 100; i++) {
        vector.AddBack(i);
    }
    cout << vector << endl;
    for (int i = 0; i < 99; i++) {
        vector.RemoveAt(0);
    }
    cout << vector << endl;
    return 0;
}