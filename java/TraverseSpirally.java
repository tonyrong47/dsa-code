import java.util.ArrayList;

public class TraverseSpirally {
// Function to return a list of integers denoting spiral traversal of matrix.

    public static ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        ArrayList<Integer> ans = new ArrayList<>();
        int l = 0, r = matrix[0].length - 1, t = 0, d = matrix.length - 1;
        int i = 0, j = 0;
        while( l <= r && t <= d){
            for(j = l; j <= r; j++) ans.add( matrix[t][j] );
            t++;
            if( t > d) break;
            for(i = t;i <= d; i++) ans.add( matrix[i][r] );
            r--;
            if( r < l) break;
            for(j = r; j >= l; j--) ans.add( matrix[d][j]);
            d--;
            if( t > d) break;
            for(i = d;  i >= t; i--) ans.add( matrix[i][l] );
            l++;
            if( r < l) break;
        }
        return ans;
    }
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        ArrayList<Integer> spiralTraverseList = spirallyTraverse(matrix);

        // Print the rotated matrix

        for (int val : spiralTraverseList) {
            System.out.print(val + " ");
        }

    }

}
