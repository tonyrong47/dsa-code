#include <stdio.h>

#define R1 2 // Row of first matrix
#define C1 3 // Column of first matrix (must match R2)
#define R2 3 // Row of second matrix
#define C2 2 // Column of second matrix

void multiply_matrices(int mat1[R1][C1], int mat2[R2][C2], int res[R1][C2]) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void print_matrix(int mat[R1][C2]) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Example
int main() {
    int A[R1][C1] = { {1, 2, 3}, {4, 5, 6} };
    int B[R2][C2] = { {7, 8}, {9, 10}, {11, 12} };
    int C[R1][C2];

    multiply_matrices(A, B, C);
    
    printf("Resultant Matrix (C):\n");
    print_matrix(C);

    return 0;
}