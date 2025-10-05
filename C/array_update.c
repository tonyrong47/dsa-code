/*
 * [Algorithm]: Array Update
 * [author]: tanshen-kun
 *
 * Hacktoberfest2025
 */
#include <stdio.h>

void array_update(int arr[], int pos, int value) { 
	arr[pos] = value; 
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 4, 6, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArray(arr, size);

  int pos;
  printf("Enter the postion to update(0-%d) : ", size - 1);
  scanf("%d", &pos);

  int value;
  printf("Enter the value to update : ");
  scanf("%d", &value);

  array_update(arr, pos, value);

  printf("Array After update : ");
  printArray(arr, size);

  return 0;
}
