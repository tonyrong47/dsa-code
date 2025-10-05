// Program to find the Union and Intersection of two sorted arrays
#include<iostream>
using namespace std;

int main()
{
    // Declare arrays and arrays to store union and intersection
    int arr1[100], arr2[100], uni[100], inter[100];

    // Input for first array
    cout << "Enter the no of elements in array1: ";
    int n1;
    cin >> n1;
    cout << "\nEnter " << n1 << " elements in sorted order:\n";
    for(int i = 0; i < n1; i++)
        cin >> arr1[i];

    // Input for second array
    cout << "Enter the no of elements in array2: ";
    int n2;
    cin >> n2;
    cout << "\nEnter " << n2 << " elements in sorted order:\n";
    for(int i = 0; i < n2; i++)
        cin >> arr2[i];

    // Display input arrays
    cout << "\nElements of array1:\n";
    for(int i = 0; i < n1; i++)
        cout << arr1[i] << "\t";
    cout << "\nElements of array2:\n";
    for(int i = 0; i < n2; i++)
        cout << arr2[i] << "\t";

    // -------------------------
    // Find Union of the two arrays
    // -------------------------
    int i = 0, j = 0, k = 0; // i,j for traversing arr1,arr2; k for union array index
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
        {
            // Add unique element from arr1
            if(k == 0 || uni[k-1] != arr1[i])
                uni[k++] = arr1[i];
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            // Add unique element from arr2
            if(k == 0 || uni[k-1] != arr2[j])
                uni[k++] = arr2[j];
            j++;
        }
        else
        {
            // Common element in both arrays
            if(k == 0 || uni[k-1] != arr1[i])
                uni[k++] = arr1[i];
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1 (if any)
    while(i < n1)
    {
        if(k == 0 || uni[k-1] != arr1[i])
            uni[k++] = arr1[i];
        i++;
    }

    // Add remaining elements from arr2 (if any)
    while(j < n2)
    {
        if(k == 0 || uni[k-1] != arr2[j])
            uni[k++] = arr2[j];
        j++;
    }

    // -------------------------
    // Find Intersection of the two arrays
    // -------------------------
    i = 0; j = 0;
    int l = 0; // l for intersection array index
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else
        {
            // Common element found
            if(l == 0 || inter[l-1] != arr1[i])
                inter[l++] = arr1[i];
            i++;
            j++;
        }
    }

    // Display Union
    cout << "\nUnion of array1 and array2:\n";
    for(int i = 0; i < k; i++)
        cout << uni[i] << "\t";

    // Display Intersection
    cout << "\nIntersection of array1 and array2:\n";
    for(int i = 0; i < l; i++)
        cout << inter[i] << "\t";

    return 0;
}
