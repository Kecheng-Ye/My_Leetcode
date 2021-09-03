class Solution {
    //
    private int[][][] dp;
    
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if(n == 0) return 0;
        
        if(k > n / 2){
            int dp_i_0 = 0;
            int dp_i_1 = Integer.MIN_VALUE;

            for(int i = 0; i < n; i++){
                dp_i_1 = Math.max(dp_i_1, dp_i_0 - prices[i]);
                dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            }

            return dp_i_0;
        }else{
            dp = new int[n + 1][k + 1][2];
        
            for(int i = 0; i <= k; i++){
                dp[0][i][0] = 0;
                dp[0][i][1] = Integer.MIN_VALUE;
            }

            for(int i = 0; i <= n; i++){
                dp[i][0][0] = 0;
                dp[i][0][1] = Integer.MIN_VALUE;
            }

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= k; j++){
                    dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
                }
            }
            
            return dp[n][k][0];
        }
    }
}