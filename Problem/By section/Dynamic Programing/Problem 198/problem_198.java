import java.util.*;
class Solution {
    // update rule
    // on a certain house
    // you can choose to rob it and skip the one before it
    // or you dont rob it , just rob the previous one
    private int[] dp;
    
    // Time: O(n), Space: O(n)
    public int rob(int[] nums) {
        dp = new int[(nums.length <= 0) ? 1 : nums.length + 1];
        dp[0] = 0;
        if(nums.length == 0) return 0;
        
        dp[1] = nums[0];
        
        for(int i = 2; i <= nums.length; i++){
            dp[i] = Math.max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        
        return dp[nums.length];
    }
    
}