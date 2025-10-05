import java.util.ArrayList;
import java.util.List;

public class NQueens2{
    static int ans=0;
    public static void main(String[] args) {
        int n = 4;
        System.out.println(totalNQueens(n));
    }
    public static int totalNQueens(int n) {
        List<String> board = new ArrayList<>();
        StringBuilder s = new StringBuilder();
        for(int i=0;i<n;i++){
            s.append('.');
        }
        for(int i= 0;i<n;i++){
            board.add(s.toString());
        } 
        solve(0,board,n);
        return ans;
    }
    public static void solve(int col,List<String> board,int n){
        if(col==n){
            ans++;
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
               StringBuilder temprow = new StringBuilder(board.get(row));
                temprow.setCharAt(col, 'Q');
                board.set(row, temprow.toString());
                solve(col+1,board,n);
                temprow.setCharAt(col, '.');
                board.set(row, temprow.toString());
            }
        }
    }
    public static boolean isSafe(int row,int col,List<String> board ,int n){
        int temprow = row;
        int tempcol = col;

        while(row>=0 && col>=0){
            if(board.get(row--).charAt(col--)=='Q') return false;
        }
        row=temprow;
        col=tempcol;
        while(col>=0){
            if(board.get(row).charAt(col--)=='Q') return false;
        }
        row=temprow;
        col=tempcol;
        while(row<n && col>=0){
            if(board.get(row++).charAt(col--)=='Q') return false;
        }
        return true;
    }
}