class Solution {
    // dp[i][j] = the number of delete operations that need to be done in order to make 
    // word1[0,i] and word2[0,j] equal
    // update rule: same as longest substring
    private int[][] dp;
    
    // Time: O(n * m), Space: O(n * m)
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        if(m == 0 && n == 0) return 0;
        
        dp = new int[m + 1][n + 1];
        
        dp[0][0] = 0;
        for(int i = 1; i<= m; i++){
            dp[i][0] = i;
        }
         for(int i = 1; i <= n; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1.charAt(i - 1) == word2.charAt(j - 1)){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }

            }
        }
        return dp[m][n];
        
    }
}