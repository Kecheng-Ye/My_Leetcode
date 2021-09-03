class Solution {
    // dp[i][j] = the was that the nums[0,i] can form the target sum j
    // update rule
    // dp[i][j] = dp[i - 1][j + nums[j]] + dp[i - 1][j - nums[j]]
    // means you either plus the last one or minus the last one
    // private int[][] dp;
    
    // m = total sum of nums array
    // Time: O(n * 2m), Space: O(n * 2m)
    // public int findTargetSumWays(int[] nums, int S) {
    //     if(nums.length == 0) return 0;
        
    //     int sum = 0;
    //     for(int i : nums){
    //         sum += i;
    //     }
        
    //     if(S > sum || -S > sum) return 0;
        
    //     dp = new int[nums.length + 1][2 * sum + 1];
    //     dp[0][sum] = 1;
        
    //     for(int i = 1; i <= nums.length; i++){
    //         for(int j = 0; j <= 2 * sum; j++){
    //             int if_plus = (j - nums[i - 1] < 0) ? 0 : dp[i - 1][j - nums[i - 1]];
    //             int if_minus = (j + nums[i - 1] > dp[0].length - 1) ? 0 : dp[i - 1][j + nums[i - 1]];
                
    //             dp[i][j] = if_plus + if_minus;
    //         }
    //     }
        
    //     return dp[nums.length][sum + S];
    // }
    
    // an better version
    // dp[i] = the total ways of nums array to form target sum i
    // suppose the nums can be partition into two subsets P,M s.t sum(P) - sum(M) = S
    // we want S = sum(P) - sum(M)
    // S + sum(P) + sum(M) = sum(P) - sum(M) + sum(P) + sum(M)
    // S + total_sum(num) = 2 * sum(P)
    // sum(P) = (S + total_sum(num)) / 2
    // so we want to do a subset sum problem for target (S + total_sum(num)) / 2
    // let m = (S + total_sum(num))
    // Time: O(n * m), Space: O(m)
    public int findTargetSumWays(int[] nums, int S) {
        int sum = computeArraySum(nums);
        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }
        int W = (sum + S) / 2;
        int[] dp = new int[W + 1];
        dp[0] = 1;
        for (int num : nums) {
            for (int i = W; i >= num; i--) {
                dp[i] = dp[i] + dp[i - num];
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

    // brutal force: DFS
    // public int findTargetSumWays(int[] nums, int S) {
    //     return findTargetSumWays(nums, 0, S);
    // }
    
    // private int findTargetSumWays(int[] nums, int start, int S) {
    //     if (start == nums.length) {
    //         return S == 0 ? 1 : 0;
    //     }
    //     return findTargetSumWays(nums, start + 1, S + nums[start])
    //             + findTargetSumWays(nums, start + 1, S - nums[start]);
    // }
}