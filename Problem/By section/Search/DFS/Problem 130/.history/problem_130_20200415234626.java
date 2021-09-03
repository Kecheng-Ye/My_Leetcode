import java.util.*;
class Solution {
    public void solve(char[][] board) {
        if(board.length == 0) return;      
        
        for(int i = 0; i < board.length; i++){
            DFS(board, i, 0);
            DFS(board, i, board[0].length - 1);
        }
        
        for(int i = 0; i < board[0].length; i++){
            DFS(board, 0, i);
            DFS(board, board.length - 1, i);
        }
        
        HashMap<Character, Character> chang_rule = new HashMap<>(){{
            put('T', 'O');
            put('O', 'X');   
            put('X', 'X');  
        }};
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                board[i][j] = chang_rule.get(board[i][j]);
            }
        }
    }
    
    public void DFS(char[][] board, int i, int j){
        if(i < 0 || i > board.length - 1 || j < 0 || j > board[0].length - 1 || board[i][j] != 'O'){
            return;
        }else{
            board[i][j] = 'T';
            
            DFS(board, i - 1, j);
            DFS(board, i + 1, j);
            DFS(board, i, j + 1);
            DFS(board, i, j - 1);

        }
    }
}