#include "2_sort_matrix.h"

void sort_matrix(int** matrix, int m = 10, int n = 10) {
        int temp;
        for (int** ptr1 = matrix; ptr1 < matrix + n; ptr1++) {
                for (int* ptr2 = *ptr1 ; ptr2 < *ptr1 + m - 1; ptr2++) {
                        for (int* ptr3 = ptr2 + 1; ptr3 < *ptr1 + m; ptr3++) {
                                if (*ptr3 < *ptr2) {
                                        temp = *ptr3;
                                        *ptr3 = *ptr2;
                                        *ptr2 = temp;
                                }
                        }
                }
        }
}


