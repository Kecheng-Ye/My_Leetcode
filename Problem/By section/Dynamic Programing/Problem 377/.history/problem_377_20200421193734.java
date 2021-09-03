class Solution {
    // dp[i] = possible combination of ways to sum to i using nums
    // update rule
    // dp[i] = dp[i] + dp[i - each_num]
    // meaning we will update the 
    private int[] dp;
    
    public int combinationSum4(int[] nums, int target) {
        if(target <= 0 || nums.length == 0) return 0;
        
        dp = new int[target + 1];
        dp[0] = 1;
        
        for(int i = 1; i <= target; i ++){
            for(int num : nums){
                if(i >= num){
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
}