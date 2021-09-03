class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 0) return true;
        
        int count = 0;

        for(int i = 1; i < nums.length && count < 2; i++){
            if(nums[i] >= nums[i - 1]) continue;

            count++;

            if(i - 2 > 0 && nums[i - 2] > nums[i]){
                nums[i] = nums[i - 1];
            }else{
                nums[i - 1] = nums[i];
            }
        }
        
        return count < 2;
    }
}

public class problem_665{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.checkPossibility(new int[]{3,4,2,3}));
    }
}