#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Find the maximum value in the array
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create count array of size (maxElement+1)
    vector<int> count(maxElement + 1, 0);

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Build the sorted array
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (non-negative integers): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array using Counting Sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
