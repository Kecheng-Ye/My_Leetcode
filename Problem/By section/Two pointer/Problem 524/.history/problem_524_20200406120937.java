import java.util.*;

class Solution {
    public String findLongestWord(String s, List<String> d) {
        String ans = "";
        for(String each_string : d){
            if(each_string.length() < ans.length()){
                continue;
            }
            
            int i = 0, j = 0;
            while(i < s.length() && j < each_string.length()){
                if(s.charAt(i) == each_string.charAt(j)){
                    j ++;
                }
                
                i ++;
            }
            
            if(j == each_string.length()){
                ans = (ans.length() > each_string.length() && ans.compareTo(each_string) > 0) ? ans : each_string;
            }
        }
        
        return ans;
    }
}

public class problem_524{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findLongestWord("abpcplea", new String[]{"a", "b", "c"}));
    }
}