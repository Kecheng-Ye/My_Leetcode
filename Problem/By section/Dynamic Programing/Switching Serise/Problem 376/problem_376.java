// class Node{
//     int len;
//     int diff;
    
//     public Node(){
//         this.len = 1;
//         this.diff = 0;
//     }
// }

class Solution {
    // private Node[] dp;
    
    // Time: O(n), Space: O(n)
    public int wiggleMaxLength(int[] nums) {
//         if(nums.length <= 1) return nums.length;
    
        
//         dp = new Node[nums.length];
//         for(int i = 0 ; i < nums.length; i++){
//             dp[i] = new Node();
//         }
        
//         int ans = 1;
            
//         for(int i = 1; i < nums.length; i++){
//             for(int j = 0; j < i; j++){
                
//                 int prev_diff = dp[j].diff;
//                 int curr_diff = nums[i] - nums[j];
//                 if(prev_diff == 0 && curr_diff != 0){
//                     dp[i].diff = curr_diff;
//                     dp[i].len = dp[j].len + 1;
//                 }
                
//                 if((prev_diff * curr_diff) < 0){
//                     if(dp[i].len < dp[j].len + 1){
//                         dp[i].diff = curr_diff;
//                         dp[i].len = dp[j].len + 1;
//                     }
//                 }
//             }
//             ans = Math.max(ans, dp[i].len);
//         }
        
//         return ans;
        
        if(nums.length <= 1) return nums.length;
        
        // down = the length of the longest subsequence ends with nums[i] and nums[i - 1] > nums[i]
        // up = the length of the longest subsequence ends with nums[i] and nums[i - 1] < nums[i]
        int up = 1;
        int down = 1;
        
        // there is only three cases for nums[i]
        // case 1: nums[i - 1] > nums[i]
        // update rule: down = up + 1
        // case 2: nums[i - 1] < nums[i]
        // update rule: up = down + 1
        // case 3: nums[i - 1] == nums[i]
        // do not update
        for(int i = 1; i < nums.length; i++){
            if(nums[i] > nums[i - 1]){
                up = down + 1;
            }else if(nums[i] < nums[i - 1]){
                down = up + 1;
            }else{
                continue;
            }
        }
        
        return Math.max(up, down);
    }
}