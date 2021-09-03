class Solution {
    // dp[i][j][k] = the maximal profit that one can receive at day i with j trasanction opeartion 
    // and in k state(0 for no stock, 1 for holding the stock)
    // update rule
    // 1. dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
    // meaning if you dont have stock today, you maybe don't have it yesterday or you cell the stock today
    // 2. dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i] - fee)
    // meaning if you have stock today, you maybe have it at yesterday or you buy the stock today
    private int[][][] dp;
    
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        if(n == 0) return 0;
        
        // if k > n/2
        // meaning you can do trascantion on everyday
        // so you don't have limitation
        // k = infinity
        if(k > n / 2){
            int dp_i_0 = 0;
            int dp_i_1 = Integer.MIN_VALUE;

            for(int i = 0; i < n; i++){
                dp_i_1 = Math.max(dp_i_1, dp_i_0 - prices[i]);
                dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            }

            return dp_i_0;
        }else{
            // with limitation
            dp = new int[n + 1][k + 1][2];
        
            // base case 1: 
            // dp[0][i][0] = 0, dp[0][i][1] = -infinity
            // you have no profit on day 0 with no stock
            // you cannot hold a stock on day 0
            for(int i = 0; i <= k; i++){
                dp[0][i][0] = 0;
                dp[0][i][1] = Integer.MIN_VALUE;
            }

            // base case 2: 
            // dp[i][0][0] = 0, dp[i][0][1] = -infinity
            // you have no profit with no stock and no trasanction done
            // you cannot hold a stock with no trasanction done
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