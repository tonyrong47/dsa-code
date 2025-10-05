/*
 *
 * [Algorithm] : Array Insertion
 * [author]: tanshen-kun
 *
 * Hacktoberfest2025
 */
#include <stdio.h>

void array_insert(int arr[], int *size, int value, int pos) {
  for (int i = *size; i > pos; i--) {
    arr[i] = arr[i - 1];
  }

  arr[pos] = value;
  (*size)++;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[50] = {1, 3, 4, 5, 6, 7, 8, 9};
  int size = 8;

  printf("Array : ");
  printArray(arr, size);

  int pos;
  printf("Enter the position to Insert (0 to %d): ", size - 1);
  scanf("%d", &pos);

  int value;
  printf("Enter the value to insert : ");
  scanf("%d", &value);

  array_insert(arr, &size, value, pos);

  printf("Array after insertion : ");
  printArray(arr, size);

  return 0;
}
