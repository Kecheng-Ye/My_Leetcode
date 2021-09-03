class Solution {
    private int[] dp;
    
    public int rob(int[] nums) {
        dp = new int[(nums.length <= 0) ? 1 : nums.length + 1];
        dp[0] = 0;
        if(nums.length == 0) return 0;
        
        dp[1] = nums[0];
        int ans = dp[1];
        
        for(int i = 2; i <= nums.length; i++){
            dp[i] = Math.max(dp[i - 2] + nums[i - 1], dp[i - 1]);
            ans = Math.max(ans, dp[i]);
        }
        
        return ans;
    }
    
}