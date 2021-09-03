#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Update rule
    // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
    // Time: O(n), Space: O(1)
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int size = nums.size();
        int prev_2 = nums[0];
        int prev_1 = max(prev_2, nums[1]);
        int result = prev_1;

        for(int i = 2; i < size; i++) {
            result = max(prev_1, prev_2 + nums[i]);
            prev_2 = prev_1;
            prev_1 = result;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}