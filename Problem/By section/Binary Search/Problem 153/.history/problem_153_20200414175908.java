class Solution {
    public int findMin(int[] nums) {
        if(nums.length <= 1) return nums[0];
        
        return bin_search(nums, 0, nums.length - 1);
    }
    
//     public int bin_search(int[] nums, int l, int r){
//         if(l <= r){
             
//             int middle = l + (r - l) / 2;
            
//             if(nums[middle - 1] > nums[middle] && nums[middle + 1] > nums[middle]){
//                 return nums[middle];
//             }else{
//                 return Math.min(bin_search(nums, l, middle - 1), bin_search(nums, middle + 1, r));
//             }
//         }else{
//             return Integer.MAX_VALUE;
//         }
//     }
    
    public int bin_search(int[] nums, int l, int r){
        if(l == r) return nums[l];
        
        int middle = l + (r - l) / 2;
        
        if(nums[middle] < nums[r]){
            return bin_search(nums, l, middle);
        }else{
            return bin_search(nums, middle + 1, r);
        }
    }
}