import java.util.*;

class Solution {
    public String findLongestWord(String s, List<String> d) {
        String ans = "";
        // iterate all of the elements in the List
        for(String each_string : d){
            int ans_len = ans.length();
            int target_len = each_string.length();

            // if the candidate's length is no longer than the current answer
            // we will pass it
            if(target_len < ans_len){
                continue;
            }
            
            // use two pointer to determine whether the candiate is a subset of s
            int i = 0, j = 0;
            // either word goes to the end will terminate the loop
            while(i < s.length() && j < target_len){
                // if there is a match of character
                // then we will increment the candidate's pointer
                if(s.charAt(i) == each_string.charAt(j)){
                    j ++;
                }
                
                // we will always increment the orginal string pointer because
                // we have to continue matching
                i ++;
            }
            
            // if the candidate is indeed a subset of s
            if(j == target_len){
                // we will compare the candidate to the current answer
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