import java.util.*;
class Solution {
    // dp[i] = least number of perfect square numbers that sums up to i
    // update rule
    // dp[i] = argmin_j (dp[i - j^2] + 1)
    private int[] dp;
    
    public int numSquares(int n) {
        dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 0; i <= n; i++){
            double sqrt = Math.sqrt(i);
            // Note here
            // how to check if a number is a whole squre
            if (sqrt == Math.floor(sqrt)) {
                dp[i] = 1;
            }else{
                dp[i] = i;
                for(int j = (int)sqrt; j >= 1; j--){
                    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        
        return dp[n];
    }
}