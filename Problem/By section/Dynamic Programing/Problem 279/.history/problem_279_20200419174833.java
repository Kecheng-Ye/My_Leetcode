import java.util.*;
class Solution {
    private int[] dp;
    
    public int numSquares(int n) {
        dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 0; i <= n; i++){
            double sqrt = Math.sqrt(i);
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