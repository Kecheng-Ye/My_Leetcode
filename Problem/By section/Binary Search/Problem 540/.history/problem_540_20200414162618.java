class Solution {
    // Time: O(log(n)), Space: O(1)
    public int singleNonDuplicate(int[] nums) {
        if(nums.length <= 2) return nums[0];

        // search if the abnormal is from the subarray [1, nums - 2]
        int ans = bin_search(nums, 1, nums.length - 2);
        
        // if it is not from the above array
        // then we successfully narrow our candidate to either left bound or right bound 
        if(ans < 0){
            ans = (nums[0] != nums[1]) ? nums[0] : nums[nums.length - 1];
        }
        
        return ans;
    }
    
    // binary search purpose:
    // want to find a number at index i that is nums[i - 1] < nums[i] < nums[i + 1]
    // if no such number, return -1
    public int bin_search(int[] nums, int l, int r){
        if(l <= r){
            int middle = l + (r - l) / 2;
            
            if(nums[middle] > nums[middle - 1] && nums[middle] < nums[middle + 1]){
                return nums[middle];
            }else{
                return Math.max(bin_search(nums, l, middle - 1), bin_search(nums, middle + 1, r));
            }
        }else{
            return -1;
        }
    }
}