import java.util.*;

class Solution{
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        
        if(candidates.length == 0) return ans;
        
        boolean[] visited = new boolean[candidates.length];
        backtrack(candidates, 0 ,target, ans, new ArrayList<Integer>(), visited);
        
        return ans;
    }
    
    public void backtrack(int[] candidates, int index, int target, List<List<Integer>> ans, List<Integer> current, boolean[] visited){
        if(target == 0){
            ans.add(new ArrayList<Integer>(current));
        }else{
            
            for(int i = index; i < candidates.length && candidates[i] <= target; i++){
                if(i != 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]){
                    continue;
                }
                
                // if(visited[i]) continue;
                
                current.add(candidates[i]);
                visited[i] = true;
                
                backtrack(candidates, i + 1, target - candidates[i], ans, current, visited);
                
                visited[i] = false;
                current.remove(current.size() - 1);
            }
        }
    }
}
