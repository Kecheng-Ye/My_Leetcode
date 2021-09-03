import java.util.*;
class Solution {
    public void solve(char[][] board) {
         ArrayList<Integer> delete = new ArrayList<Integer>();
         delete.add(0);
         for(int i = 0; i < board.length; i++){
             for(int j = 0; j < board[0].length; j ++){
                 if(board[i][j] == 'O'){
                     BFS(board, i, j, delete);
                     System.out.println("After diging " + i + " " + j);
                     printBoard(board);
                     System.out.println("\n\n");
                 }
                 delete.set(0, 0);
             }
         }
    }
    
    public void BFS(char[][] board, int i, int j, ArrayList<Integer> delete){
        if(i < 0 || i > board.length - 1 || j < 0 || j > board[0].length - 1 || board[i][j] != 'O'){
            return;
        }else{
            board[i][j] = 'X';
            
            if(i == 0 || i == board.length - 1 || j == 0 || j == board[0].length - 1){
                delete.set(0, 1);
            }
            
            BFS(board, i - 1, j, delete);
            BFS(board, i + 1, j, delete);
            BFS(board, i, j + 1, delete);
            BFS(board, i, j - 1, delete);
            
            if(delete.get(0) == 1){
                board[i][j] = 'T';
            }
        }
    }

    public void printBoard(char[][] board){
        for(char[] arr : board){
            for(char i : arr){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}

public class problem_130{
    public static void main(String[] args) {
        char[][] test = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
        Solution sol = new Solution();
        sol.printBoard(test);
        System.out.println();
        sol.solve(test);
        sol.printBoard(test);
    }
}