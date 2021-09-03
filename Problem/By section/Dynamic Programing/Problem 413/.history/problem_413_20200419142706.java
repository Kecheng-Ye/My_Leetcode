class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        if(n < 3) return 0;
        
        
        int[] dp = new int[n];
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