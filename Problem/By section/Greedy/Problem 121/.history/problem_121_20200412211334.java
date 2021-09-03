class Solution {
    // Time: O(n), Space: O(1)
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        
        int min = prices[0];
        int ans = Integer.MIN_VALUE;
        
        // check for the local min and update the 
        // potential profit gained by the that min
        for(int i = 1; i < prices.length; i ++){
            if(prices[i] < min){
                min = prices[i];
            }else{
                ans = Math.max(ans, prices[i] - min);
            }
        }
        
        return (ans < 0) ? 0 : ans;
    }
}