import java.util.*;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        if(s.length() == 0) return ans;
        
        backtrack(s, 0, ans, new ArrayList<String>());
        
        return ans;
    }
    
    public void backtrack(String s, int start, List<List<String>> ans, ArrayList<String> current){
        if(start == s.length()){
            ans.add(new ArrayList<String>(current));
            return;
        }
        
        for(int i = start; i < s.length(); i++){
            if(isPalindorme(s.substring(start, i + 1))){
                current.add(s.substring(start, i + 1));
                backtrack(s, i + 1, ans, current);
                current.remove(current.size() - 1);
            }
        }
    }
    
    public boolean isPalindorme(String s){
        if(s.length() == 1) return true;
            
        for(int i = 0, j = s.length() - 1; i <= j; i ++, j --){
            if(s.charAt(i)  != s.charAt(j)) return false;
        }
        
        return true;
    }
}