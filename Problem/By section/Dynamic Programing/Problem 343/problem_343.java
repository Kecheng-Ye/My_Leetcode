class Solution {
    // dp[i] = the maximum product of i
    // update rule
    // dp[i] = argmax_j (dp[i - j] * dp[j])
    // Note here: if j <= 4, dp[j] <= j
    // Also we can cut half of the searching space because
    // eg. dp[2] * dp[4] = dp[4] * dp[2]
    private int[] dp;
    
    // Time: O(n^2), Space: O(n)
    public int integerBreak(int n) {
        if(n <= 1) return 0;
        
        dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i = 3; i <= n; i++){
            int limit = (int)(i / 2);
            
            for(int j = 1; j <= limit; j++){
                int temp_1 = ((i - j) > 4) ? dp[i - j] : (i - j);
                int temp_2 = (j > 4) ? dp[j] : j;
                dp[i] = Math.max(dp[i], temp_1 * temp_2);
            }
        }
        return dp[n];
    }
}