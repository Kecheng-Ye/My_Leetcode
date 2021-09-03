class solution{
    public int[] searchRange(int[] nums, int target) {
        int left = bin_search_left(nums, target, 0, nums.length - 1);
        
        if(left == -1){
            return new int[]{-1, -1};
        }else{
            return new int[]{left, bin_search_right(nums, target, left, nums.length - 1)};
        }
    }

    public int bin_search_left(int[] nums, double target, int l, int r){
        if(l <= r){
            int middle = l + (r - l) / 2;
            
            if(nums[middle] == target && (middle - 1 < 0 || nums[middle -1] < target)){
                return middle;
            }else{
                return Math.max(bin_search_left(nums, target, l, middle - 1), bin_search_left(nums, target, middle + 1, r)); 
            }
        }else{
            return -1;
        }
    }

    public int bin_search_right(int[] nums, double target, int l, int r){
        if(l <= r){
            int middle = l + (r - l) / 2;
            
            if(nums[middle] == target && (middle + 1 > nums.length - 1 || nums[middle + 1] > target)){
                return middle;
            }else{
                return Math.max(bin_search_right(nums, target, l, middle - 1), bin_search_right(nums, target, middle + 1, r)); 
            }
        }else{
            return -1;
        }
    }
}