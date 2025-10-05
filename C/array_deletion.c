/*
 *
 * [Algorithm] : Array Deletion
 * [author] : tanshen-kun
 *
 * Hacktoberfest2025
 */

#include <stdio.h>

void array_delete(int arr[], int *size, int pos) {
  for (int i = pos; i < *size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  (*size)--;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArray(arr, size);

  int pos;
  printf("Enter postion to delete (0-%d) : ", size - 1);
  scanf("%d", &pos);

  array_delete(arr, &size, pos);

  printf("Array After Deletion : ");
  printArray(arr, size);

  return 0;
}
