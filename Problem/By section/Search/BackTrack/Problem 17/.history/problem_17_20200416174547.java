import java.util.*;

class Solution{
    private final Map<Character, String> keyboard = new HashMap<>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};
    
    // Time: O(n * c), Space: O(n * c)
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<String>();
        if(digits.length() == 0) return ans;
        backtrack(digits, ans, "");
        return ans;
    }
    
    public void backtrack(String digits, List<String> ans, String result){
        if(digits.length() == 0){
            ans.add(result);
            return;
        }
        
        
        if(digits.charAt(0) == '1'){
            backtrack(digits.substring(1), ans, result);
        }else{
            String potential = keyboard.get(digits.charAt(0));
            StringBuilder builder = new StringBuilder();
            builder.append(result);
                
            for(int i = 0; i < potential.length(); i++){
                builder.append(potential.charAt(i));
                backtrack(digits.substring(1), ans, builder.toString());
                builder.deleteCharAt(result.length());
            }
        }
    }
}


public class problem_17{
    public static void main(String[] args) {
        String input = "234";
        Solution sol = new Solution();
        System.out.println(sol.letterCombinations(input));
    }
}
