#include <stdio.h>

#define MAX 100

// Created Function to get valid integer input within range
int getValidInput(const char *prompt, int max) {
    int value;
    while (1) {
        printf("%s (1 to %d): ", prompt, max);
        if (scanf("%d", &value) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
        } else if (value < 1 || value > max) {
            printf("Value out of range. Try again.\n");
        } else {
            break;  // Valid input
        }
    }
    return value;
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX], transpose[MAX][MAX];

    // Get validated input for rows and columns
    rows = getValidInput("Enter the number of rows", MAX);
    cols = getValidInput("Enter the number of columns", MAX);

    // Input matrix elements
    printf("\nEnter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            while (scanf("%d", &matrix[i][j]) != 1) {
                while (getchar() != '\n');  // Clear input buffer
                printf("Invalid input. Enter an integer for [%d][%d]: ", i, j);
            }
        }
    }

    // Compute transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Print transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
