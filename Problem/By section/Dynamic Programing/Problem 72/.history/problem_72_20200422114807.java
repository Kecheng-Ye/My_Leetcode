class Solution {
    private int[][] dp;
    
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