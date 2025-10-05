#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void displayArray(int arr[], int size);
int insertElement(int arr[], int size, int element, int position);
int deleteElement(int arr[], int size, int position);
int searchElement(int arr[], int size, int element);
void updateElement(int arr[], int size, int position, int newValue);
void displayMenu();

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
int insertElement(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Error: Array is full. Cannot insert element.\n");
        return size;
    }
    
    if (position < 0 || position > size) {
        printf("Error: Invalid position. Position should be between 0 and %d.\n", size);
        return size;
    }
    
    // Shift elements to the right
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[position] = element;
    size++;
    
    printf("Element %d inserted at position %d successfully.\n", element, position);
    return size;
}

// Function to delete an element at a specific position
int deleteElement(int arr[], int size, int position) {
    if (size == 0) {
        printf("Error: Array is empty. Cannot delete element.\n");
        return size;
    }
    
    if (position < 0 || position >= size) {
        printf("Error: Invalid position. Position should be between 0 and %d.\n", size - 1);
        return size;
    }
    
    int deletedElement = arr[position];
    
    // Shift elements to the left
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    size--;
    printf("Element %d deleted from position %d successfully.\n", deletedElement, position);
    return size;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

// Function to update an element at a specific position
void updateElement(int arr[], int size, int position, int newValue) {
    if (size == 0) {
        printf("Error: Array is empty. Cannot update element.\n");
        return;
    }
    
    if (position < 0 || position >= size) {
        printf("Error: Invalid position. Position should be between 0 and %d.\n", size - 1);
        return;
    }
    
    int oldValue = arr[position];
    arr[position] = newValue;
    printf("Element at position %d updated from %d to %d successfully.\n", position, oldValue, newValue);
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Array Manipulation Menu ===\n");
    printf("1. Display Array (Traversal)\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Search Element\n");
    printf("5. Update Element\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position, newValue, searchResult;
    
    printf("=== Array Manipulation Program in C ===\n");
    printf("Maximum array size: %d\n", MAX_SIZE);
    
    // Initialize array with some sample data (optional)
    printf("\nDo you want to initialize the array with sample data? (1 for Yes, 0 for No): ");
    int initChoice;
    scanf("%d", &initChoice);
    
    if (initChoice == 1) {
        int sampleData[] = {10, 20, 30, 40, 50};
        int sampleSize = sizeof(sampleData) / sizeof(sampleData[0]);
        
        for (int i = 0; i < sampleSize; i++) {
            arr[i] = sampleData[i];
        }
        size = sampleSize;
        printf("Array initialized with sample data.\n");
        displayArray(arr, size);
    }
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Traversal - Display Array
                printf("\n--- Array Traversal ---\n");
                displayArray(arr, size);
                break;
                
            case 2: // Insertion
                printf("\n--- Insert Element ---\n");
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                size = insertElement(arr, size, element, position);
                break;
                
            case 3: // Deletion
                printf("\n--- Delete Element ---\n");
                if (size == 0) {
                    printf("Array is empty. Nothing to delete.\n");
                } else {
                    displayArray(arr, size);
                    printf("Enter position to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    size = deleteElement(arr, size, position);
                }
                break;
                
            case 4: // Searching
                printf("\n--- Search Element ---\n");
                if (size == 0) {
                    printf("Array is empty. Nothing to search.\n");
                } else {
                    printf("Enter element to search: ");
                    scanf("%d", &element);
                    searchResult = searchElement(arr, size, element);
                    
                    if (searchResult != -1) {
                        printf("Element %d found at position %d.\n", element, searchResult);
                    } else {
                        printf("Element %d not found in the array.\n", element);
                    }
                }
                break;
                
            case 5: // Update
                printf("\n--- Update Element ---\n");
                if (size == 0) {
                    printf("Array is empty. Nothing to update.\n");
                } else {
                    displayArray(arr, size);
                    printf("Enter position to update (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    printf("Enter new value: ");
                    scanf("%d", &newValue);
                    updateElement(arr, size, position, newValue);
                }
                break;
                
            case 6: // Exit
                printf("\nThank you for using Array Manipulation Program!\n");
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); // Clear the input buffer
        getchar(); // Wait for Enter key
    }
    
    return 0;
}
