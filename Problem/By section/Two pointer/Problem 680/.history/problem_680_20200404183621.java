class Solution {
    public boolean validPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        boolean deleted = false;
        
        while(i < j){
            System.out.println(i + " " + j + " " + deleted);
            if(s.charAt(i) == s.charAt(j)){
                System.out.println("Matched");
                i ++;
                j --;
            }else{
                System.out.println("UnMatched");
                if(!deleted){
                    if(s.charAt(i + 1) == s.charAt(j)){
                        System.out.println("Move i");
                        i ++;
                        deleted = true;
                    }else if(s.charAt(i) == s.charAt(j - 1)){
                        System.out.println("Move j");
                        j --;
                        deleted = true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
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