class Solution {
    // Time: O(w * h), Space: O(1)
    public int maxAreaOfIsland(int[][] grid) {
        int max_area = 0;
        
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
    
    public int BFS(int[][] grid, int i, int j){
        if(i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1 || grid[i][j] == 0) return 0;
        int area = 1;
        grid[i][j] = 0;
        area += BFS(grid, i - 1, j);
        area += BFS(grid, i + 1, j);
        area += BFS(grid, i, j - 1);
        area += BFS(grid, i, j + 1);
        
        
        return area;
    }
}