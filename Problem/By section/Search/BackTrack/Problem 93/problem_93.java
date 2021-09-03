import java.util.*;
class Solution {
    private final int limit = 255;
    
    // Time: O(3^4), Space: O(n)
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        if(s.length() < 4) return ans;
        
        backtrack(s, ans, 4, "");
        return ans;
    }
    
    // Key to back track
    // candiate, current answer, end condition, constrain
    public void backtrack(String s, List<String> ans, int dot_num, String result){
        // end condition
        if(dot_num == 0 || s.length() == 0){
            if(s.length() == 0 && dot_num == 0){
                ans.add(result.substring(1, result.length()));
                return;
            }
            return;
        }

        StringBuilder builder = new StringBuilder();
        builder.append(result);

        // each potentional candidate
        for(int i = 1; i <= 3 && i <= s.length(); i ++){
            int potential = Integer.parseInt(s.substring(0, i));
            // the constrain
            if(potential > limit || i >= 2 && s.charAt(0) == '0'){
                break;
            }else{
                // try the potential candidate
                builder.append('.');
                builder.append(potential);
                backtrack(s.substring(i), ans, dot_num - 1, builder.toString());
                // and remove the candidate
                builder.delete(result.length(), result.length() + i + 1);
            }
        }
    }
}

public class problem_93{
    public static void main(String[] args) {
        String s = "010010";
        Solution sol = new Solution();
        System.out.println(sol.restoreIpAddresses(s));

    } 
}
