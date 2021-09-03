import java.util.*;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        
        if(n == 0 || k == 0 || k > n){
            return ans;
        }
        
        backtrack(n, k, 1, new ArrayList<Integer>(), ans);
        return ans;
    }
    
    public void backtrack(int n, int k, int num, ArrayList<Integer> current, List<List<Integer>> ans){
        if(k == 0){
            ans.add(new ArrayList<Integer>(current));
            return;
        }
        
        
        for(int i = num; i <= n + 1 - k; i++){
                current.add(i);
                
                backtrack(n, k - 1, i + 1, current, ans);
                    
                current.remove(current.size() - 1);
        }
    }
    
}