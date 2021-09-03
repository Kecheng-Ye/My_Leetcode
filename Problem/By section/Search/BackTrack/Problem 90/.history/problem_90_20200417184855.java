import java.util.*;

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        
        if(nums.length == 0) return ans;
        
        backtrack(nums, 0, ans, new ArrayList<Integer>());
        return ans;
    }
    
    public void backtrack(int[] nums, int index, List<List<Integer>> ans, ArrayList<Integer> current){
        if(index == nums.length){
            ans.add(new ArrayList<Integer>(current));
            return;
        }
        
        current.add(nums[index]);
        backtrack(nums, index + 1, ans, current);
        current.remove(current.size() - 1);
        
        // very important
        // if there is two same element
        // after we traverse all the possibility of first one
        // we must only investigate the probability of including the second one
        if(index > 0 && current.size() > 0 && current.get(current.size() - 1) == nums[index]) return;
        
        backtrack(nums, index + 1, ans, current);
    }
}