class Solution {
    private final int[][] directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    public boolean exist(char[][] board, String word) {
        if(word.length() == 0) return true;
        if(board.length == 0) return false;
        
        boolean[][] isVisited = new boolean[board.length][board[0].length];
        
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == word.charAt(0)){
                    if(backtrack(board, word, i, j, isVisited, 0)) return true;
                    
                }
            }
        }
        
        return false;
    }
    
    public boolean backtrack(char[][] board, String word, int i, int j, boolean[][] isVisited, int index){
        if(word.length() == index){
            return true;
        }
        
        if(i < 0 || i > board.length - 1 || j < 0 || j > board[0].length - 1 || isVisited[i][j] || word.charAt(index) != board[i][j]){
            return false;
        }
        
        
        isVisited[i][j] = true;
        
        for(int[] direction : directions){
            if(backtrack(board, word, i + direction[0], j + direction[1], isVisited, index + 1)) return true;

        }
        
        isVisited[i][j] = false;
        return false;
    }
}