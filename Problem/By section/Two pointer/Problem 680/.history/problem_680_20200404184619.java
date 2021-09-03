class Solution {
    public boolean validPalindrome(String s) {
        // two pointer
        for(int i = 0, j = s.length() - 1; i < j; i ++, j --){
            // if the two pointer mismatch
            if(s.charAt(i) != s.charAt(j)){
                // we have to try either skip left pointer or right pointer
                return validPalindrome_helper(s, i + 1, j) || validPalindrome_helper(s, i, j - 1);
            }
        }
    
        return true;
    }
    
    // regular Palindrome checking starting at left i and right j
    public boolean validPalindrome_helper(String s, int i, int j) {
        while(i < j){
            if(s.charAt(i ++) != s.charAt(j --)){
                return false;
            }
        }
        
        return true;
    }
}

public class problem_680{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    }
}