import java.util.Arrays;

public class moveZeros {

    public void moveZeroes(int[] nums) {
        int j = 0; // pointer for non-zero position

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                // Swap nums[i] with nums[j]
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
    }

    public static void main(String[] args) {
        moveZeros mz = new moveZeros();
        
        int[] nums = {0, 1, 0, 3, 12};
        System.out.println("Before: " + Arrays.toString(nums));
        
        mz.moveZeroes(nums);
        
        System.out.println("After:  " + Arrays.toString(nums));
    }
}
