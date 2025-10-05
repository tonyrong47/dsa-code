#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Outer loop for the number of passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparison and swapping
        // n - i - 1 because the last 'i' elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    printArray(data, n);

    // Sort the array
    bubbleSort(data, n);

    printf("Sorted array: ");
    printArray(data, n);

    return 0;
}