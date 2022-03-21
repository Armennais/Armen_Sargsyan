#include <iostream>
<<<<<<< HEAD
#include <string>
using namespace std;
void swap(char* a, char* b);
int main()
{
    string num;

    int a,b;
    cout << "Input number: ";
    //Imput array elements
    cin >> num;
    cout << endl << "Input position to swap: ";
    
    cin >> a >> b;
    
    //check that 'a' and 'b' is in range
    if ((a < 0 || a > num.size()) || (b < 0 || b > num.size()))
=======
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
>>>>>>> 2a94bc652f8e3b49039ddf63806a20be5b4d40be
    {
        do
        {
            cout << "Out of range,try again: ";
            cin >> a >> b;
<<<<<<< HEAD
        }while((a < 0 || a > num.size()) || (b < 0 || b > num.size()));
    }
    //this for negative numbers
    if (num[0] == '-')
    {
        a += 1;
        b += 1;
    }
    
    swap(&num[a-1],&num[b - 1]);
    cout << "Output: " << num << endl;
    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
=======
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
>>>>>>> 2a94bc652f8e3b49039ddf63806a20be5b4d40be
