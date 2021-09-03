class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        
        int dp_i_1_0 = 0;
        int dp_i_2_0 = 0;
        int dp_i_1_1 = Integer.MIN_VALUE;
        int dp_i_2_1 = Integer.MIN_VALUE;
        
        for(int i = 1; i <= prices.length; i++){
            dp_i_2_0 = Math.max(dp_i_2_0, dp_i_2_1 + prices[i - 1]);
            dp_i_2_1 = Math.max(dp_i_2_1, dp_i_1_0 - prices[i - 1]);
            dp_i_1_0 = Math.max(dp_i_1_0, dp_i_1_1 + prices[i - 1]);
            dp_i_1_1 = Math.max(dp_i_1_1, - prices[i - 1]);
        }
        
        return dp_i_2_0;
    }
}