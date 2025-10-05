#include <iostream>
using namespace std;

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int itr = 0; itr < n; itr++) {
        cout << arr[itr] << " ";
    }
    cout << endl;
    
    // Bubble sort algorithm
    for(int itr = 0; itr < n - 1; itr++) {
        // Last itr elements are already in place, so we don't need to check them
        for(int j = 0; j < n - itr - 1; j++) {
            // Swap if current element is greater than next
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    cout << "Sorted array: ";
    for(int itr = 0; itr < n; itr++) {
        cout << arr[itr] << " ";
    }
    cout << endl;
    

    return 0;
}