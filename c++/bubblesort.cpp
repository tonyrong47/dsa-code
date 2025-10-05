#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    int n = arr.size();

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
