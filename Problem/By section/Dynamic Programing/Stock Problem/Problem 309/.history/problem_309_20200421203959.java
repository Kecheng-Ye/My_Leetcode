class Solution {
    private int[][] dp;
    
    public int maxProfit(int[] prices) {
//         if(prices.length == 0) return 0;
        
//         dp = new int[prices.length + 1][2];
//         dp[0][0] = 0;
//         dp[0][1] = Integer.MIN_VALUE;
        
//         for(int i = 1; i <= prices.length; i++){
//             dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
//             if(i - 2 >= 0){
//                 dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
//             }else{
//                 dp[i][1] = -prices[i - 1];
//             }
//         }
        
//         return dp[prices.length][0];
        
        int n = prices.length;
        int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
        int dp_pre_0 = 0; // 代表 dp[i-2][0]
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = Math.max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
}