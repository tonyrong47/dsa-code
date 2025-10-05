/*
 *
 * [Algorithm]: Array Searching
 * [author]: tanshen-kun
 *
 * Hacktoberfest2025
 */
#include <stdio.h>

int array_search(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  // if not found
  return -1;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 1, 42, 12, 34, 12, 56, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Array : ");
  printArray(arr, size);

  int key;
  printf("Enter the key to search : ");
  scanf("%d", &key);

  int index = array_search(arr, size, key);
  if (index != -1) {
    printf("Element found at index %d\n", index);
  } else {
    printf("Element not found!\n");
  }

  return 0;
}
