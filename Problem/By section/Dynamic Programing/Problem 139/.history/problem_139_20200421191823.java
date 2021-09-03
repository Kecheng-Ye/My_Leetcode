import java.util.*;
class Solution {
    // dp[i] = if the wordDict can construct the s[0,i]
    // update rule
    // dp[i] = dp[i] || dp[i - word.length()] if this word can matach s[i - word.length(), i]
    // meaning either we use this word for matching or not
    private boolean[] dp;
    
    // Time: O(s * n), Space: O(s)
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s.length() == 0) return true;
        if(wordDict.size() == 0) return false;
        
        dp = new boolean[s.length() + 1];
        dp[0]= true;
        
        // the reason why we iterate this way is because
        // word matching requires sequence
        for(int i = 1; i <= s.length(); i++){
            for(String word : wordDict){
                if(i >=  word.length() && s.substring(i - word.length(), i).equals(word)){
                    dp[i] = dp[i] || dp[i - word.length()];
                }
            }
        }
        
        return dp[s.length()];
    }
}