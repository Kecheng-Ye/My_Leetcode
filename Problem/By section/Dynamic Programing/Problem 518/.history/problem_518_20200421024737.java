class Solution {
    // dp[i] = the amount of ways to pay i
    // update rule
    // dp[i] = dp[i] + dp[i - each_coin]
    private int[] dp;
    
    public int change(int amount, int[] coins) {
        if(amount == 0) return 1;
        if(coins.length == 0) return 0;
        
        dp = new int[amount + 1];
        dp[0] = 1;
        
        // the reason why we first iterate coin
        // because we secure that the using ways won't be duplicate
        for(int coin : coins){
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
}