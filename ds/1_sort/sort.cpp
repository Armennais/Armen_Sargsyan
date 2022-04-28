#include <iostream>
#include <ctime>
#include <random>

using namespace std;

mt19937 gen(time(nullptr));
int genNumber(int a = -1000, int b = 1000)
{
    return gen() % (b - a + 1) + a;
}
void swap(int &a, int &b);
void insertionSort(int *arr, int length);
void bubbleSort(int *a, int n);
void merge(int *a, int l, int m, int r);
void mergeSort(int *arr, int l, int r);



int main()
{
    const int SIZE = 20000;
    int iarray[SIZE];
    int barray[SIZE];
    int marray[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        iarray[i] = genNumber();
        barray[i] = iarray[i];
        marray[i] = iarray[i];
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
    //merge sort
    start_time = clock();
    mergeSort(marray, 0 , SIZE);
    cout << "Merge sort time := "
         << 1000.0 * (double)(clock() - start_time) / CLOCKS_PER_SEC
         << "ms\n";
    return 0;
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

void merge(int *a, int l, int m, int r)
{
    int first = l;
    int second = m + 1;
    int base = 0;
    int *marr = new int[r - l + 1];
    while (first <= m && second <= r)
    {
        while (first <= m && a[first] <= a[second])
        {
            marr[base] = a[first];
            base++;
            first++;
        }

        while (second <= r && a[first] > a[second])
        {
            marr[base] = a[second];
            base++;
            second++;
        }
    }

    if (second == r + 1)
    {
        for (int i = first; i <= m; i++)
        {
            marr[base] = a[i];
            base++;
        }
    }
    else
    {
        for (int i = second; i <= r; i++)
        {
            marr[base] = a[i];
            base++;
        }
    }

    for (int i = 0; i <= r - l; i++)
    {
        a[i + l] = marr[i];
    }

    delete[] marr;
}

void mergeSort(int *arr, int l, int r)
{
    if (l != r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}