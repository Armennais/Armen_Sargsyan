#include <iostream>
#include "2_sort_matrix.h"
using namespace std;
void display_matrix(int**, int, int);
void sort_matrix(int**, int, int);
int main() {
        int height = 5;
        int width = 5;
        int**  matrix = new int*[height];
        for (int** ptr1 = matrix; ptr1 < matrix + height; ptr1++) {
                *ptr1 = new int[width];
                for (int* ptr2 = *ptr1; ptr2 < *ptr1 + width; ptr2++) {
                        *ptr2 = rand() % 9 + 1 ; 
                }
        }
        display_matrix(matrix, width, height);
        cout << endl;
        sort_matrix(matrix, width, height);
        display_matrix(matrix, width, height);
        return 0;
}
void display_matrix(int** matrix, int m, int n) {
        for (int** ptr1 = matrix; ptr1 < matrix + n; ptr1++) {
                for (int* ptr2 = *ptr1; ptr2 < *ptr1 + m; ptr2++) {
                        cout << *ptr2 << " ";
                }
                cout << endl;
        }
}

