import java.util.*;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        if(nums.length == 0) return ans;
        
        backtrack(nums, 0, ans, new ArrayList<Integer>());
            
        return ans;
    }
    
    public void backtrack(int[] nums, int index, List<List<Integer>> ans, ArrayList<Integer> current){
        if(index == nums.length){
            ans.add(new ArrayList<Integer>(current));
            return;
        }
        
        backtrack(nums, index + 1, ans, current);
        
        current.add(nums[index]);
        backtrack(nums, index + 1, ans, current);
        current.remove(current.size() - 1);
    }
}