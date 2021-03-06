class Solution {
    // dp[i][j] = the least distance from grid[0][0] to grid[i][j]
    // update rule
    // dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    // because the grid[i][j] can only come from the left cell or the upper cell
    private int[][] dp;
    
    // Time: O(w * h), Space: O(w * h)
    public int minPathSum(int[][] grid) {
        if(grid.length == 0) return 0;
        
        dp = new int[grid.length][grid[0].length];
        
        int prev = 0;
        for(int i = 0; i < grid.length; i ++){
            dp[i][0] = prev + grid[i][0];
            prev = dp[i][0];
        }
        
        prev = 0;
        for(int i = 0; i < grid[0].length; i ++){
            dp[0][i] = prev + grid[0][i];
            prev = dp[0][i];
        }
        
        for(int i = 1; i < grid.length; i ++){
            for(int j = 1; j < grid[0].length; j ++){
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }    
        }
        
        return dp[grid.length - 1][grid[0].length - 1];
    }   
}