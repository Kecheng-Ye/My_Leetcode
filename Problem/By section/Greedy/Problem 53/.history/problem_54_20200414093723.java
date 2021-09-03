class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0) return 0;
        
        int curr_sum = nums[0];
        int ans = curr_sum;
        
        for(int i = 1; i < nums.length; i++){
            curr_sum = (curr_sum > 0) ? curr_sum + nums[i] : nums[i];
            ans = Math.max(ans, curr_sum);
        }
        
        return ans;
    }
}