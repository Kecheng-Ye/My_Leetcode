import java.util.*;
class Solution {
    // dp[i] = the length of longest chain ends with pairs[i]
    // Note: We have to sort it first
    // update rule: 
    // dp[i] = argmax_j (dp[j] + 1)            s.t pairs[j][1] < pairs[i][0]
    private int[] dp;
    
    // Time: O(n^2), Space: O(n)
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (arr1, arr2) -> ((arr1[0] - arr2[0] == 0) ? arr1[1] - arr2[1] : arr1[0] - arr2[0]));
        if(pairs.length == 0) return 0;
        
        dp = new int[pairs.length];
        int ans = 1;
            
        Arrays.fill(dp, 1);
        for(int i = 1; i < pairs.length; i++){       
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        
        return ans;
    }
}