import java.util.*;

class Solution {
    public String findLongestWord(String s, List<String> d) {
        String ans = "";
        for(String each_string : d){
            int ans_len = ans.length();
            int target_len = each_string.length();

            if(target_len < ans_len){
                continue;
            }
            
            int i = 0, j = 0;
            while(i < s.length() && j < target_len){
                if(s.charAt(i) == each_string.charAt(j)){
                    j ++;
                }
                
                i ++;
            }
            
            if(j == target_len){
                ans = (ans_len >= target_len && ans.compareTo(each_string) < 0) ? ans : each_string;
            }
        }
        
        return ans;
    }
}

public class problem_524{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findLongestWord("abpcplea", new ArrayList<String>(Arrays.asList("a", "b", "c"))));
    }
}