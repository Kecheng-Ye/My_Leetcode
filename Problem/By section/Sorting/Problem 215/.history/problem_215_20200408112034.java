class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        
        return 0;
    }

    public void findKthLargest_helper(int[] nums, int k, int l, int r) {
        if(l >= r) return;
        
        int m = (int)(Math.random() * (r - l + 1));
        swap(nums, r, l + m);

        int target_index = partition(nums, l, r);
        if(target_index == k){
            return;
        }else if(target_index > k){
            findKthLargest_helper(nums, k, l, target_index - 1);
        }else{
            findKthLargest_helper(nums, k, target_index + 1, r);
        }
    }

    public int partition(int[] nums, int l, int r){
        int target = nums[r];

        int i = l;
        int j = r - 1;

        while(true){
            while(nums[i] <= target && i < r){
                i ++;
            }

            while(nums[j] >= target && j > i){
                j --;
            }

            if(i >= j){
                break;
            }

            swap(nums, i, j);
        }

        if(i < r) swap(nums, i , r);

        return i;
    }

    public void swap(int[] nums, int l, int r){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
}