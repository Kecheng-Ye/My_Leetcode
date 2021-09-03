class Solution {
    private final int[] candidates = {1,2,3,4,5,6,7,8,9};
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        
        if(k == 0 || n <= 0) return ans;
        
        backtrack(k, n, 0, ans, new ArrayList<Integer>());
        
        return ans;
    }
    
    public void backtrack(int k, int n, int index, List<List<Integer>> ans, ArrayList<Integer> current){
        if(n <= 0 || k <= 0){
            if(n == 0 && k == 0){
                ans.add(new ArrayList<Integer>(current));
                return;
            }
            return;
        }
        
        for(int i = index; i < candidates.length && candidates[i] <= n; i ++){
            current.add(candidates[i]);
            
            backtrack(k - 1, n - candidates[i], i + 1, ans, current);
            
            current.remove(current.size() - 1);
        }
    }
}