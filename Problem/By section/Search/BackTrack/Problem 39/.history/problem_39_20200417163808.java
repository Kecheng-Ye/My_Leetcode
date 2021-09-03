import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        if(candidates.length == 0) return ans;
        
        backtrack(candidates, 0 ,target, ans, new ArrayList<Integer>());
        
        return ans;
    }
    
    public void backtrack(int[] candidates, int index, int target, List<List<Integer>> ans, List<Integer> current){
        if(target == 0){
            ans.add(new ArrayList<Integer>(current));
        }else{
            
            for(int i = index; i < candidates.length && candidates[i] <= target; i++){
                current.add(candidates[i]);
                
                backtrack(candidates, i ,target - candidates[i], ans, current);
                
                current.remove(current.size() - 1);
            }
        }
    }   
}