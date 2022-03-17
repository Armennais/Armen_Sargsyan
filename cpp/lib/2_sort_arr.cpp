#include "2_sort_matrix.h"

void sort_matrix(int** matrix, int m = 10, int n = 10) {
        int temp;
        for (int* ptr1 = *matrix; ptr1 < *matrix + n; ptr1++) {
                for (int** ptr2 = matrix ; ptr2 < matrix + m - 1; ptr2++) {
                        for (int** ptr3 = ptr2 + 1; ptr3 < matrix + m; ptr3++) {
                                int x = *(*ptr2 + (ptr1 - *matrix));
				int y = *(*ptr3 + (ptr1 - *matrix));
				if (x > y) {
                                *(*ptr2 + (ptr1 - *matrix)) = y;
				*(*ptr3 + (ptr1 - *matrix)) = x;
				}
                        }
                }
        }
}


