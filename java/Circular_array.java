
import java.util.Scanner;

class CircularArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // Constraint check
        if (n <= 1 || n >= 11) {
            System.out.println("Invalid Array Size");
            return;
        }

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Print all circular rotations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[(i + j) % n] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
