import java.util.*;
class Solution {
    // Time: O(n), Space: O(1)
    public int findKthLargest(int[] nums, int k) {
        findKthLargest_helper(nums, k, 0, nums.length - 1);

        return nums[nums.length - k];
    }

    // do a one way quick sort for searching the 
    // number exactly placed in the 'n - k' index
    public void findKthLargest_helper(int[] nums, int k, int l, int r) {
        if(l >= r) return;
        
        // randomize the piviot in order to
        // avoid the worst case scenario of quick sort
        int m = (int)(Math.random() * (r - l + 1));
        swap(nums, r, l + m);
        
        // find the index for the piviot
        int target_index = partition(nums, l, r);

        // if the index = n - k
        // then it is the target number we are looking for
        if(target_index == nums.length - k){
            return;
        }else if(target_index > nums.length - k){
            // if the target_index is bigger than n - k
            // we know the target number should be smaller than the current target index
            findKthLargest_helper(nums, k, l, target_index - 1);
        }else{
            // if the target_index is smaller than n - k
            // we know the target number should be bigger than the current target index
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



    /*****************************************************/
    // Another Approach by min heap
    // why min heap?
    // because we want kth largest, so every time a bigger element add into
    // the heap, we will pop the smallest one

    // Time: O(nlog(k)) Space: (k)
    // public int findKthLargest(int[] nums, int k) {
    //     // max heap 
    //     // PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    //     //min heap
    //     PriorityQueue<Integer> pq = new PriorityQueue<>();
        

    //     for(int i : nums){
    //         pq.add(i);

    //         if(pq.size() > k){
    //             pq.remove();
    //         }
    //     }
        
    //     return pq.remove();
    // }
}