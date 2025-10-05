import java.util.ArrayList;
import java.util.Scanner;

public class SortArrayList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        
        // Create ArrayList of integers
        ArrayList<Integer> numbers = new ArrayList<>();
        
        // Read n integers and add them to the ArrayList
        for (int i = 0; i < n; i++) {
            numbers.add(scanner.nextInt());
        }
        
        // Sort the ArrayList in ascending order using bubble sort
        bubbleSort(numbers);
        
        // Print the sorted elements
        for (int i = 0; i < numbers.size(); i++) {
            System.out.print(numbers.get(i));
            if (i < numbers.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
        
        scanner.close();
    }
    
    /**
     * Sorts the ArrayList in ascending order using bubble sort algorithm
     * @param list The ArrayList to be sorted
     */
    public static void bubbleSort(ArrayList<Integer> list) {
        int n = list.size();
        
        // Bubble sort implementation
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Compare adjacent elements
                if (list.get(j) > list.get(j + 1)) {
                    // Swap elements if they are in wrong order
                    int temp = list.get(j);
                    list.set(j, list.get(j + 1));
                    list.set(j + 1, temp);
                }
            }
        }
    }
}
