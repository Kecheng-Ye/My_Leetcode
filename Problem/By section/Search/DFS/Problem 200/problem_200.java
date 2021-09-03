class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == '1'){
                    count++;
                    BFS(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    public void BFS(char[][] grid, int i, int j){
        if(i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1 || grid[i][j] == '0'){
            return;
        }
        
        grid[i][j] = '0';
        BFS(grid, i - 1, j);
        BFS(grid, i + 1, j);
        BFS(grid, i, j + 1);
        BFS(grid, i, j - 1);
    }
}