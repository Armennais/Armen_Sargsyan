#include <iostream>
#include <ctime>
#include <random>
 
using namespace std;
 
mt19937 gen(time(nullptr));
 
int genNumber(int a = -1000, int b = 1000)
{
    return gen() % (b - a + 1) + a;
}
 
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
void insertionSort(int *arr, int length)
{
    int i, j, tmp;
    for (i = 1; i < length; ++i)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}
 
void bubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
 
int main()
{
    const int SIZE = 20000;
    int iarray[SIZE];
    int barray[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        iarray[i] = genNumber();
        barray[i] = iarray[i];
    }
    // insertion sort
    clock_t start_time = clock();
    insertionSort(iarray, SIZE);
    cout << "Insertion sort time := "
         << 1000.0 * (double)(clock() - start_time) / CLOCKS_PER_SEC
         << "ms\n";
 
    // bubble sort
    start_time = clock();
    bubbleSort(barray, SIZE);
    cout << "Bubble sort time := "
         << 1000.0 * (double)(clock() - start_time) / CLOCKS_PER_SEC
         << "ms\n";
         
    return 0;
}