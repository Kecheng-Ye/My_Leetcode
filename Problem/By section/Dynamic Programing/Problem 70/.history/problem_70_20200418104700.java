class Solution {
    // update rule: dp[n] = dp[n - 1] + dp[n - 2]
    // for the last step you take
    // you can either choose to go one step
    // or two step
    private int[] dp;

    // Time: O(n), Space: O(n)
    public int climbStairs(int n) {
        dp = new int[(n <= 2) ? 3 : n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        if(n <= 2) return dp[n];
            
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
}