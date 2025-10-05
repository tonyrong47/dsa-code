import java.util.ArrayList;
import java.util.List;

class Solution {
    /**
     * Given an m x n matrix, return all elements of the matrix in spiral order.
     * * @param matrix The input m x n matrix.
     * @return A list of elements in spiral order.
     */
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return result;
        }

        int numRows = matrix.length;
        int numCols = matrix[0].length;

        // Initialize the four boundaries
        int top = 0;
        int bottom = numRows - 1;
        int left = 0;
        int right = numCols - 1;

        while (top <= bottom && left <= right) {

            // 1. Traverse Right (from left to right boundary on the current top row)
            for (int col = left; col <= right; col++) {
                result.add(matrix[top][col]);
            }
            top++; // Move the top boundary down

            // Check if all rows have been processed
            if (top > bottom) break;

            // 2. Traverse Down (from new top to bottom boundary on the current right column)
            for (int row = top; row <= bottom; row++) {
                result.add(matrix[row][right]);
            }
            right--; // Move the right boundary in

            // Check if all columns have been processed
            if (left > right) break;

            // 3. Traverse Left (from new right to left boundary on the current bottom row)
            // This is done in reverse order
            for (int col = right; col >= left; col--) {
                result.add(matrix[bottom][col]);
            }
            bottom--; // Move the bottom boundary up

            // Check if all rows have been processed
            if (top > bottom) break;

            // 4. Traverse Up (from new bottom to top boundary on the current left column)
            // This is done in reverse order
            for (int row = bottom; row >= top; row--) {
                result.add(matrix[row][left]);
            }
            left++; // Move the left boundary in
        }

        return result;
    }
}