class Solution {
    // dp[i][j] = the length of longest common subsequence of text1[0,i] and text2[0,j]
    // update rule
    // if the last character of text1[0,i] == the last character of text2[0,j]
    // dp[i][j] = dp[i - 1][j - 1] + 1
    // else
    // dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])          either we dont use the last character of text1 or text2
    private int[][] dp;
    
    // Time: O(m * n), Space: O(m * n)
    public int longestCommonSubsequence(String text1, String text2) {
        if(text1.length() == 0 || text2.length() == 0){
            return 0;
        }
        
        int m = text1.length();
        int n = text2.length();
        
        dp = new int[m + 1][n + 1];
        
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                 if(text1.charAt(i - 1) == text2.charAt(j - 1)){
                     dp[i][j] = dp[i - 1][j - 1] + 1;
                 }else{
                     dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                 }
            }
        }
        return dp[m][n];
    }
}