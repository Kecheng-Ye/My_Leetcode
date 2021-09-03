import java.util.*;
class Solution {
    private final int limit = 255;
    
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        if(s.length() < 4) return ans;
        
        backtrack(s, ans, 4, "");
        return ans;
    }
    
    public void backtrack(String s, List<String> ans, int dot_num, String result){
        if(s.length() == 0 && dot_num == 0){
            ans.add(result.substring(1, result.length()));
            return;
        }

        StringBuilder builder = new StringBuilder();
        builder.append(result);
        for(int i = 1; i <= 3 && i <= s.length(); i ++){
            int potential = Integer.parseInt(s.substring(0, i));
            if(potential > limit || i >= 2 && s.charAt(0) == '0'){
                break;
            }else{
                builder.append('.');
                builder.append(potential);
                backtrack(s.substring(i), ans, dot_num - 1, builder.toString());
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
