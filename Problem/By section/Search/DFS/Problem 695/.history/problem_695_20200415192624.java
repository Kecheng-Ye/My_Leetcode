class Solution {
    // Time: O(w * h), Space: O(1)
    public int maxAreaOfIsland(int[][] grid) {
        int max_area = 0;
        
        // we dig every possible island and do a bfs on it
        // in order to get the max area including this single '1'
        for(int i = 0; i < grid.length; i ++){
            for(int j = 0; j < grid[0].length; j ++){
                if(grid[i][j] == 0){
                    continue;
                }else{
                    max_area = Math.max(max_area, BFS(grid, i, j));   
                }
            }
        }
        
        return max_area;
    }
    
    // BFS method
    public int BFS(int[][] grid, int i, int j){
        // either we go out of bound or
        // we meet a '0'
        // we return area of 0
        if(i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1 || grid[i][j] == 0) return 0;
        
        // we will count this area
        // and flip it in order to remember it
        int area = 1;
        grid[i][j] = 0;

        // then discover four potential direction for expansion
        area += BFS(grid, i - 1, j);
        area += BFS(grid, i + 1, j);
        area += BFS(grid, i, j - 1);
        area += BFS(grid, i, j + 1);
        
        
        return area;
    }
}