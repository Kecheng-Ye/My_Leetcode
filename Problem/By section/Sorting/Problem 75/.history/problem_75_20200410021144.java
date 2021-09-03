class Solution {
    public void sortColors(int[] nums) {
        int i = 0;
        int j = 0;
        int k = nums.length - 1;
        
        while(j <= k){
            System.out.printf("i = %d, j = %d, k = %d \n", i, j, k);
            print(nums);
            if(nums[j] == 0){
                swap(nums, i, j);
                i ++;
            }else if(nums[j] == 2){
                swap(nums, j, k);
                k --;
            }else{
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
        sol.sortColors(new int[]{2,0,2,1,1,0});
    }
}