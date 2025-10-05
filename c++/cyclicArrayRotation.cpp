// Program to cyclically rotate an array by one position
#include<iostream>
using namespace std;

int main()
{
    // Declare array and variable to store number of elements
    int arr[100], n;

    // Input number of elements
    cout << "Enter no of elements: ";
    cin >> n;

    // Input array elements
    cout << "\nEnter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Display entered elements
    cout << "\nEntered elements:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    // Rotate array elements by 1 position to the right
    int temp = arr[n - 1]; // Store last element temporarily
    for(int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i]; // Shift each element one position to the right
    }
    arr[0] = temp; // Move last element to the first position

    // Display rotated array
    cout << "\nRotated elements:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    return 0;
}
