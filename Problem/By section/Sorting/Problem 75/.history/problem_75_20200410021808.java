class Solution {
    // Time: O(n), Space: O(1)
    public void sortColors(int[] nums) {
        // Three pointer: 
        // i stands for the biggest index for 0
        // k stands for the smallest index for 1
        // 
        int i = 0;
        int j = 0;
        int k = nums.length - 1;
        
        while(j < k){
            if(nums[j] == 0){
                swap(nums, i, j);
                i ++;
                j ++;
            }else if(nums[j] == 2){
                swap(nums, j, k);
                k --;
            }else{
                j ++;
            }
        }

        print(nums);
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
        sol.sortColors(new int[]{2,0,2,1,1,0});
    }
}