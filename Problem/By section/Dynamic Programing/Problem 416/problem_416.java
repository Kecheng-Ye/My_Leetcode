class Solution{
    // dp[i][j] = can the subset of nums[0, j] achieve a sum of i
    // update rule
    // dp[i][j] = dp[i][j - 1] || dp[i - nums[j]][j - 1]
    // which means we will either use the last element to achieve i or not use the last one to achieve i
    // private boolean[][] dp;
    
    // Time: O(n * m), Space: O(n * m)
    // Too Slow!!!!!!!!!!!!!!!!!!!!
    // public boolean canPartition(int[] nums) {
    //     if(nums.length == 0) return false;
        
    //     int sum = 0;
    //     for(int i : nums){
    //         sum += i;
    //     }
    //     if(sum % 2 != 0) return false;
        
    //     int target = sum / 2;
        
    //     dp = new boolean[target + 1][nums.length + 1];
    //     for(int i = 0; i <= nums.length; i++){
    //         dp[0][i] = true;
    //     }
    //     Important here !!!!!!!!
    //     we can switch the order of updating
    //     to make the process quickly
    //     for(int j = 1; j <= nums.length; j++){
    //         for(int i = 1; i <= target; i++){
    //             if(i - nums[j - 1] < 0){
    //                 dp[i][j] = dp[i][j - 1];
    //             }else{
    //                 dp[i][j] = dp[i - nums[j - 1]][j - 1] || dp[i][j - 1];
    //             }
    //         }
    //         if(dp[target][j]) return true;
    //     }
        
    //     return dp[target][nums.length];
    // }


    public boolean canPartition(int[] nums) {
        int sum = computeArraySum(nums);
        if (sum % 2 != 0) {
            return false;
        }
        int W = sum / 2;
        boolean[] dp = new boolean[W + 1];
        dp[0] = true;
        for (int num : nums) {                 // 0-1 背包一个物品只能用一次
            for (int i = W; i >= num; i--) {   // 从后往前，先计算 dp[i] 再计算 dp[i-num]
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[W];
    }
    
    private int computeArraySum(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
}