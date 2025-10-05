public class NQueens {
    static int N = 8; // You can change this for different N

    // Function to print the board
    static void printBoard(int board[][]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print((board[i][j] == 1 ? "Q " : ". "));
            System.out.println();
        }
        System.out.println();
    }

    // Check if queen can be placed
    static boolean isSafe(int board[][], int row, int col) {
        int i, j;

        // Check this row on left
        for (i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;

        // Check upper diagonal
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        // Check lower diagonal
        for (i = row, j = col; i < N && j >= 0; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    // Solve using backtracking
    static boolean solveNQUtil(int board[][], int col) {
        if (col >= N) {
            printBoard(board);
            return true;
        }

        boolean res = false;
        for (int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;

                // Recursion
                res = solveNQUtil(board, col + 1) || res;

                // Backtrack
                board[i][col] = 0;
            }
        }
        return res;
    }

    static void solveNQ() {
        int board[][] = new int[N][N];
        if (!solveNQUtil(board, 0)) {
            System.out.println("Solution does not exist");
        }
    }

    public static void main(String args[]) {
        solveNQ();
    }
}
