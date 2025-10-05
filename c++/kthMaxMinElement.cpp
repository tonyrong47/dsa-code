//Program to find k-th maximum and k-th minimum element in an array
#include<iostream>
using namespace std;

int main()
{
    // Declare an array and variable to store the number of elements
    int arr[100], n;

    // Take input for number of elements
    cout << "Enter the number of elements in array: ";
    cin >> n;

    // Input array elements
    cout << "\nEnter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Display the original array
    cout << "Elements in array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    // -------------------------
    // Array Sorting using Selection Sort
    // -------------------------
    for(int i = 0; i < n; i++)
    {
        int minIndex = i; // Assume current index has minimum
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j; // Update minIndex if smaller element found
            }
        }

        // Swap if minimum is not at current position
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Display the sorted array
    cout << "\nSorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    // -------------------------
    // Find k-th minimum and k-th maximum
    // -------------------------
    cout << "\nEnter K: ";
    int k;
    cin >> k;

    int kmin = arr[k-1];   // k-th minimum after sorting
    int kmax = arr[n-k];   // k-th maximum after sorting

    // Display results
    cout << "\n" << k << "th min element: " << kmin << "\n";
    cout << k << "th max element: " << kmax;

    return 0;
}
