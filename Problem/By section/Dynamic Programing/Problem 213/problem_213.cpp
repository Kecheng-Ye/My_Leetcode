#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Update rule: 
    // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]) with different start and end points
    // Time: O(n), Space: O(1)
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }else {
            int size = nums.size();
            
            // rob first, then stop at the second last element
            int prev_2 = nums[0];
            int prev_1 = max(nums[1], prev_2);
            int result_1 = prev_1;

            for(int i = 2; i < size - 1; i++) {
                result_1 = max(prev_1, prev_2 + nums[i]);
                prev_2 = prev_1;
                prev_1 = result_1;
            }

            // rob second, then stop at the last element
            prev_2 = nums[1];
            prev_1 = max(nums[2], prev_2);
            int result_2 = prev_1;

            for(int i = 3; i < size; i++) {
                result_2 = max(prev_1, prev_2 + nums[i]);
                prev_2 = prev_1;
                prev_1 = result_2;
            }

            return max(result_1, result_2);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}