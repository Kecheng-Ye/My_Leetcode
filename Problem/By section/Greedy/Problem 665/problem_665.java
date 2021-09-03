class Solution {
    // Time: O(n), Space: O(1)
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 0) return true;
        
        // count for the change of number
        int count = 0;
        
        for(int i = 1; i < nums.length && count < 2; i++){
            // if it is non-decreasing
            if(nums[i] >= nums[i - 1]) continue;

            count++;

            // we defaultly may change the nums[i - 1] to nums[i]
            // since it wont demage the non-decreasing order of [i,i + 1,.....]
            // while if nums[i - 2] is greater than nums[i]
            // we have change nums[i] to nums[i - 1] in order to match the non-decreasing order of [0, 1, ...., i - 2, i - 1]
            if(i - 2 >= 0 && nums[i - 2] > nums[i]){
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