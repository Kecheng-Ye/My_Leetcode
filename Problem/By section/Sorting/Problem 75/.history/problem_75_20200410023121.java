class Solution {
    // Time: O(n), Space: O(1)
    public void sortColors(int[] nums) {
        // Three pointer: 
        // i stands for the biggest index for 0
        // k stands for the smallest index for 1
        // j stamds for the smallest index for 2
        int i = 0;
        int j = 0;
        int k = nums.length - 1;
        
        // important for j <= k
        // counter example {2, 0 ,1}
        while(j <= k){
            // when the middle pointer meet 0
            // swap with small pointer 
            // and increment both
            if(nums[j] == 0){
                swap(nums, i, j);
                i ++;
                j ++;
            }else if(nums[j] == 2){
                // when the middle pointer meet 2
                // swap with big pointer 
                // and decrement big pointer 
                swap(nums, j, k);
                k --;
            }else{
                // when the middle pointer meet 1
                // just decrement middle pointer
                j ++;
            }
        }

    }
    
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void print(int[] nums){
        for(int i : nums){
            System.out.print(i + " ");
        }

        System.out.println();
    }
}

public class problem_75{
    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.sortColors(new int[]{2, 0, 1});
    }
}