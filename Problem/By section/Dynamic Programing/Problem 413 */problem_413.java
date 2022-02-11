class Solution {
    // dp[i] = the number of Arithmetic sequence ending with A[i]
    // update rule
    // dp[i] = dp[i - 1] + 1
    // copying all the combination of previous dp[i - 1] and plus 1 for forming a bigger sequence
    private int[] dp;

    // Time: O(n), Space: O(n)
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        if(n < 3) return 0;
        
        
        dp = new int[n];
        int ans = 0;
        int prev_diff = (A[1] - A[0]);
        
        for(int i = 2; i < n; i++){
            if((A[i] - A[i - 1]) == prev_diff){
                dp[i] = dp[i - 1] + 1;
            }else{
                prev_diff = A[i] - A[i - 1];   
            }
            ans += dp[i];
        }
        
        return ans;
    }
}