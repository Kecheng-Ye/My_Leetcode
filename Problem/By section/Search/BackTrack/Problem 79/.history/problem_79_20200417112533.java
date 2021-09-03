class Solution {
    private final int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    // Time: O(w * h), Space: O(w * h) 
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0) return true;
        if(board.length == 0) return false;
        
        boolean[][] isVisited = new boolean[board.length][board[0].length];
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                // only we match the first character
                // we start back track
                if(board[i][j] == word.charAt(0)){
                    if(backtrack(board, word, i, j, isVisited, 0)) return true;
                    
                }
            }
        }
        
        return false;
    }
    
    // back track method
    public boolean backtrack(char[][] board, String word, int i, int j, boolean[][] isVisited, int index){
        // the success condition
        if(word.length() == index){
            return true;
        }
        
        // the fail condition
        if(i < 0 || i > board.length - 1 || j < 0 || j > board[0].length - 1 || isVisited[i][j] || word.charAt(index) != board[i][j]){
            return false;
        }
        
        // we mark this state as visited
        isVisited[i][j] = true;
        
        // continue next state exploration
        for(int[] direction : directions){
            if(backtrack(board, word, i + direction[0], j + direction[1], isVisited, index + 1)) return true;

        }
        
        // after exploration, we wipe the record of this state
        isVisited[i][j] = false;

        // return to the previous state
        return false;
    }
}