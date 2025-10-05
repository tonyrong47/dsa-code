import java.util.ArrayList;
import java.util.Scanner;

class Sort_Ascending_Order{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Step 1: Read number of elements
        System.out.println("Enter no of elements:");
        int n = sc.nextInt();
        ArrayList<Integer> numbers = new ArrayList<>();

        // Step 2: Read elements into ArrayList
        System.out.println("Enter the integers:");
        for (int i = 0; i < n; i++) {
            numbers.add(sc.nextInt());
        }

        //Bubble sort
        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = 0; j < numbers.size() - i - 1; j++) {
                if (numbers.get(j) > numbers.get(j + 1)) {
                    // Swap
                    int temp = numbers.get(j);
                    numbers.set(j, numbers.get(j + 1));
                    numbers.set(j + 1, temp);
                }
            }
        }
        //print
        for (int i = 0; i < numbers.size(); i++) {
            System.out.print(numbers.get(i));
            if (i < numbers.size() - 1) {
                System.out.print(" ");
            }
        }

        sc.close();
    }
}
