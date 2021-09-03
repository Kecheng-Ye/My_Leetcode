import java.util.*;
class Solution {
    public void solve(char[][] board) {
         ArrayList<Integer> delete = new ArrayList<Integer>();
         delete.add(0);
         for(int i = 0; i < board.length; i++){
             for(int j = 0; j < board[0].length; j ++){
                 if(board[i][j] == 'O'){
                     BFS(board, i, j, delete);
                 }
                 delete.set(0, 0);
             }
         }
    }
    
    public void BFS(char[][] board, int i, int j, ArrayList<Integer> delete){
        if(i < 0 || i > board.length - 1 || j < 0 || j > board[0].length - 1 || board[i][j] == 'X'){
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
                board[i][j] = 'O';
            }
        }
    }
}