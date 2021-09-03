class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 0) return true;
        
        boolean flag = (nums[0] > nums[1]) ? false : true;
        int current_max = (nums[0] > nums[1]) ? nums[1] : nums[0];
        
        for(int i = 1; i < nums.length; i++){
            int temp_1 = nums[i];
            System.out.println(current_max + " " + flag);
            if(temp_1 >= current_max){
                current_max = temp_1;
            }else{
                if(!flag){
                    return false;
                }else{
                    current_max = nums[i - 2];
                    flag = false;
                    continue;
                }
            }
            
            
        }
        
        return true;
    }
}

public class problem_665{
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.checkPossibility(new int[]{4,2,3}));
    }
}