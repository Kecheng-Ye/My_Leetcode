class Solution {
    // dp[i] = the length of longest subsequence ends with nums[i]
    // update rule
    // dp[i] = argmax_j (dp[j] + 1)        s.t nums[j] < nums[i]
    private int[] dp;
    
    // Time: O(n^2), Space: O(n)
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        
        int max = Integer.MIN_VALUE;
        dp = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            max = Math.max(max, dp[i]);
        }
        
        return max;
    }
    
//     public int lengthOfLIS(int[] nums) {
//     int n = nums.length;
//     int[] dp = new int[n];
//     for (int i = 0; i < n; i++) {
//         int max = 1;
//         for (int j = 0; j < i; j++) {
//             if (nums[i] > nums[j]) {
//                 max = Math.max(max, dp[j] + 1);
//             }
//         }
//         dp[i] = max;
//     }
//     return Arrays.stream(dp).max().orElse(0);
// }
}