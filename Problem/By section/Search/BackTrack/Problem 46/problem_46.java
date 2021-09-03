import java.util.*;
class solutiom{
    // Time: O(n!), Space: O(n!)
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if(nums.length == 0) return ans;
        List<Integer> candidates = Arrays.asList(nums);

        backtrack(candidates, ans, new ArrayList<Integer>());
        return ans;
    }
    
    public void backtrack(List<Integer> candidates, List<List<Integer>> ans, List<Integer> current){
        if(candidates.size() == 0){
            // important
            // should new a object
            ans.add(new ArrayList<Integer>(current));
            return;
        }
        
        for(int i = 0; i < candidates.size(); i++){
            int temp = candidates.get(i);
            current.add(temp);
            candidates.remove(i);
            
            backtrack(candidates, ans, current);
            
            candidates.add(i, temp);
            current.remove(current.size() - 1);
        }
    }
}
