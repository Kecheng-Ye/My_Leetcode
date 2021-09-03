class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        
        int n = nums.length;
        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
    
    private int rob(int[] nums, int start, int end){
        int i_1 = 0;
        int i_2 = 0;
        
        for(int i = start; i <= end; i++){
            int update = Math.max(i_2 + nums[i], i_1);
            i_2 = i_1;
            i_1 = update;
        }
        
        return i_1;
    }
}