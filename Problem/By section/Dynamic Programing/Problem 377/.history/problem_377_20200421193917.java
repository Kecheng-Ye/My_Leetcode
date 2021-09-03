class Solution {
    // dp[i] = possible combination of ways to sum to i using nums
    // update rule
    // dp[i] = dp[i] + dp[i - each_num]
    // meaning we will update the dp[i] based on every possible combination of numbers
    private int[] dp;
    
    // Time: O(n * target), Space: O(target)
    public int combinationSum4(int[] nums, int target) {
        if(target <= 0 || nums.length == 0) return 0;
        
        dp = new int[target + 1];
        dp[0] = 1;
        
        // the reason we iterate this way is because
        // we want different combination
        // e.g (1,2,2) is different from (2,1,2)
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