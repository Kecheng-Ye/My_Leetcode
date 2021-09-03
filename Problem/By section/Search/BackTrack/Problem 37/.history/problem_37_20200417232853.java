import java.util.*;

class Solution {   
    private final char[] choices = {'1','2','3','4','5','6','7','8','9'};
    private boolean is_finished = false;
    
    
    public void solveSudoku(char[][] board) {
        List<List<Integer>> empty_spots = new LinkedList<>();
        
        boolean[][] row_valid = new boolean[board.length][board[0].length];
        boolean[][] col_valid = new boolean[board.length][board[0].length];
        boolean[][] block_valid = new boolean[board.length][board[0].length];

        prepare(board, row_valid, col_valid, block_valid);
        
        for(int j = 0; j < board[0].length; j++){
            for(int i = 0; i < board.length; i ++){
                if(board[i][j] == '.'){
                    empty_spots.add(Arrays.asList(i, j));
                }
            }
        }
        
        backtrack(board, empty_spots, row_valid, col_valid, block_valid );
        
    }
    
    public void backtrack(char[][] board, List<List<Integer>> empty_spots, boolean[][] row_valid, boolean[][] col_valid, boolean[][] block_valid){
        if(empty_spots.size() == 0){
            is_finished = true;
            return;
        }
        
        List<Integer> one_empty = empty_spots.remove(empty_spots.size() - 1);
        for(char choice : choices){

            int candidate = choice - '1';
            int y = one_empty.get(0);
            int x = one_empty.get(1);

            board[y][x] = choice;
            
            if(!row_valid[y][candidate] && !col_valid[x][candidate] && !block_valid[cord_2_block(y, x)][candidate]){
                row_valid[y][candidate] = true;
                col_valid[x][candidate] = true;
                block_valid[cord_2_block(y, x)][candidate] = true;
                
                backtrack(board, empty_spots, row_valid, col_valid, block_valid);
                if(is_finished) return;

                row_valid[y][candidate] = false;
                col_valid[x][candidate] = false;
                block_valid[cord_2_block(y, x)][candidate] = false;
            }
            
            board[y][x] = '.';
        }
        
        empty_spots.add(one_empty);
    }


    public void prepare(char[][] board, boolean[][] row_valid, boolean[][] col_valid, boolean[][] block_valid){
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j ++){
                if(board[i][j] == '.')  continue;
                int index = board[i][j] - '1';
                row_valid[i][index] = true;
                col_valid[j][index] = true;
                block_valid[cord_2_block(i, j)][index] = true;
            }
        }
    }

    public int cord_2_block(int i, int j){
        return (3 * (int)(i / 3) + (int)(j / 3));
    }
}