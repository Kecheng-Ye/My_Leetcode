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
        int prev = - 1;
        for(int i = 1; i <= 3; i ++){
            if(i > s.length()) break;
            int potential = Integer.parseInt(s.substring(0, i));
            if(prev == potential) continue;
            if(potential > limit){
                break;
            }else{
                builder.append('.');
                builder.append(potential);
                backtrack(s.substring(i), ans, dot_num - 1, builder.toString());
                builder.delete(result.length(), result.length() + i + 1);
                prev = potential;
            }
        }
    }
}

public class problem_93{
    public static void main(String[] args) {
    //    String s = "12.3";
    //    StringBuilder builder = new StringBuilder();
    //    int last_dot = 2;
    //    int i = 1;
    //    builder.append(s.substring(0, last_dot + i + 1));
    //    builder.append('.');
    //    builder.append(s.substring(last_dot + i + 1));
    //    System.out.println(builder.toString() + " " + (last_dot + i + 1));

        String s = "01000";
        Solution sol = new Solution();
        System.out.println(sol.restoreIpAddresses(s));

    } 
}
