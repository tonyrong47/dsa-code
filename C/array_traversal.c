/*
 *
 * [Algorithm]: Array Traversal
 * [author]: tanshen-kun
 *
 * Hacktoberfest2025
 */
#include <stdio.h>

void array_traversal(int arr[], int size) {
  printf("Array Elements : ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  array_traversal(arr, size);

  return 0;
}
