import java.util.*;
public class MajorityNumber {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the size of the array: ");
            int n = scanner.nextInt();
            int[] arr = new int[n];
            System.out.println("Enter the elements of the array:");
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            Map<Integer, Integer> countMap = new HashMap<>();
            for (int num : arr) {
                countMap.put(num, countMap.getOrDefault(num, 0) + 1);   
        }
            int majorityElement = -1;
            for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
                if (entry.getValue() > n / 2) {
                    majorityElement = entry.getKey();
                    break;
                }
            }
            if (majorityElement != -1) {
                System.out.println("The majority element is: " + majorityElement);
            } else {
                System.out.println("No majority element found.");
            }
            scanner.close();
    }
}
