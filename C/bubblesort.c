#include <stdio.h>

// Created a Function to sort array using Bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) { 
        for (int j = 0; j < n-i-1; j++) {  // Last i elements are already sorted

            // If the cur element is greater than the next performing swap

            if (arr[j] > arr[j+1]) {
                // Swapping using a temp
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Created a function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
