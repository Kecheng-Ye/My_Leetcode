class Solution {
    // dp[i][j] = the minimal editing different from word1[0,i] to word2[0,j]
    // update rule
    // if you get a character match in word1[i] and word2[j]
    // dp[i][j] = dp[i - 1][j - 1]
    // else you have to consider three opeartion
    // 1. insert, 2. delete, 3. replace
    // dp[i][j] = min( dp[i - 1][j - 1]             if we choose to replace
    //                 dp[i - 1][j]                 if we choose to delete
    //                 dp[i][j - 1])                if we choose to insert

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
                    int if_delete = dp[i - 1][j] + 1;
                    int if_insert = dp[i][j - 1] + 1;
                    int if_replace = dp[i - 1][j - 1] + 1;
                    int min = Math.min(if_delete, if_insert);
                    dp[i][j] = Math.min(min, if_replace);
                }
            }
        }
        
        return dp[m][n];
    }
}