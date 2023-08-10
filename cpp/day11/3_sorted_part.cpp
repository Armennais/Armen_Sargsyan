#include <iostream>
#include <stdlib.h>
using namespace std;

int count(int* , int , int );
int main() {
    int N, max_l = 0, f_index, num;
    
    cout << "Enter array size:";
    cin >> N;
    int *arr = new int[N];
    //random initialize
    for(int i = 0; i < N; i ++)
    {
        arr[i] = rand()%100;
    } 
    
    cout << "The array is: ";
    for(int i = 0; i < N; i ++)
    {
        cout << arr[i] << ", "; 
    } 
    cout << endl;
    
    for(int i = 0; i < N; i ++)
    {
        num = count(arr, i, N);
        if(num > max_l)
        {
            max_l = num;
            f_index = i;
        }
    }
    cout << "Output: ";
    for(int i = f_index; i <= f_index + max_l; i++)
    {
        cout << arr[i] << ", ";
    }  
    cout << endl;
    return 0;
}

int count(int* arr,int start, int N)
{
    int count = 0;
    for(int i = start; i < N - 1; i ++)
    {
        if(arr[i] <= arr[i + 1])
        {
            count ++;
        }else{
            break;
        }
        
    }
    return count;
}