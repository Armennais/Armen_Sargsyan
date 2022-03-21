#include <iostream>
using namespace std;

int main()
{
    
    const int *n ;
    int m = *n;
    cout << "Input Array size: ";
    cin >> m;
    if (m <= 0)
    {
        do
        {
            cout << "Input positive number: ";
            cin >> m;
        }while(m <= 0);
    }
    int * arr = new int[m];
    int a,b;
    cout << "Input number: ";
    //Imput array elements
    
    for(int i = 0;i < m; i++)
    {
        cin >> arr[i];
    }
    cout << endl << "Input position to swap: ";
    
    cin >> a >> b;
    //swap two element
    if ((a < 0 || a > m) || (b < 0 || b > m))
    {
        do
        {
            cout << "Out of range,try again: ";
            cin >> a >> b;
        }while((a < 0 || a > m) || (b < 0 || b > m));
    }
    
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    cout << "Output: ";
    //print array elements
    for(int i = 0;i < m;i++)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
