class Solution{
    // dp[i] = the Decode Ways for the substring of s[0, i]
    // update rule
    // dp = dp[i - 1] + dp[i - 2] (if the substring of(i - 2, i) is <= 26 && > 0)
    private int[] dp;
    
    // Time: O(n), Space: O(n)
    public int numDecodings(String s) {
        int n = s.length();
        
        if(n == 0 || s.charAt(0) == '0') return 0;
        
        dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int temp = Integer.valueOf(s.substring(i - 2, i));
            // check if this s[i] != 0
            // if yes, then we have to check the previous one != 0
            if(s.charAt(i - 1) != '0'){
                if(s.charAt(i - 2) != '0'){
                    dp[i] = dp[i - 1] + ((temp <= 26) ? dp[i - 2] : 0);   
                }else{
                    // if the previous is a 0, we can only view the s[i] as a single character
                    dp[i] = dp[i - 1];
                }  
            }else{
                // if s[i] == 0
                // we can only check the s[i -2, i] as a single letter
                dp[i] = ((temp <= 26 && temp > 0) ? dp[i - 2] : 0);
            }
        }
        
        return dp[n];
    }
}