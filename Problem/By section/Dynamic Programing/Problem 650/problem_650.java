class Solution {
    // dp[i] = meaning the least operation that you can get from 1 'A' to i 'A'
    // NOTE: since copy paste will always duplicate the whole string
    // meaning i 'A' can only be construct from its perfect divider j 'A'
    // update rule
    // dp[i] = argmin_j (dp[j] + i/j)    s.t  i % j == 0
    private int[] dp;

    // Time: O(n^2), Space: O(n)
    public int minSteps(int n) {
        if(n <= 1) return 0;
        
        dp = new int[n + 1];
        dp[1] = 0;
        
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            for(int j = 1; j <= (int)i/2; j++){
                if(i % j == 0){
                    dp[i] = Math.min(dp[i], dp[j] + i/j);
                }
            }
        }
        
        return dp[n];
    }
}