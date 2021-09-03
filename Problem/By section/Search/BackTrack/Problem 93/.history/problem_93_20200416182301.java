import java.util.*;
class Solution {
    private final int limit = 255;
    
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        if(s.length() < 4) return ans;
        
        backtrack(s, -1, ans, 0);
        return ans;
    }
    
    public void backtrack(String s, int last_dot, List<String> ans, int dot_num){
        if(dot_num > 4){
            return;
        }else if(last_dot == s.length() - 1){
            
            ans.add(s);
            return;
        }
        
        StringBuilder builder = new StringBuilder();
        System.out.println(s + " " +last_dot + " " + s.length());
        for(int i = 1; i <= 3; i ++){
            if(last_dot + i + 1 > s.length() + 1){
                break;
            }
            int end_pos = (last_dot + i + 1 > s.length()) ? s.length() : last_dot + i + 1;
            int potential = Integer.parseInt(s.substring(last_dot + 1, end_pos));
            System.out.println("The String of " + (last_dot + 1) + " " + (end_pos)  + " " + s.substring(last_dot + 1, end_pos));
            if(potential > limit){
                break;
            }else{
                builder.append(s.substring(0, end_pos));
                builder.append('.');
                builder.append(s.substring(end_pos));
                backtrack(builder.toString(), last_dot + i + 1, ans, dot_num ++);
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

        String s = "1234";
        Solution sol = new Solution();
        System.out.println(sol.restoreIpAddresses(s));

    } 
}
