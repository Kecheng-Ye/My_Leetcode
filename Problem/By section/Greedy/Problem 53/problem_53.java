class Solution {
    // Time: O(n), Space: O(1)
    public int maxSubArray(int[] nums) {
        if(nums.length == 0) return 0;
        
        int curr_sum = nums[0];
        int ans = curr_sum;
        
        // iterate through the whole array
        // we know that if the 'curr_sum' < 0, it cannot be part of the max sum
        // and we update the 'ans' every time to ensure it can record all the max sum
        for(int i = 1; i < nums.length; i++){
            curr_sum = (curr_sum > 0) ? curr_sum + nums[i] : nums[i];
            ans = Math.max(ans, curr_sum);
        }
        
        return ans;
    }
}