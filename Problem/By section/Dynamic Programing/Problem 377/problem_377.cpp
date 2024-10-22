#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j]: with first i numbers being used, how many ways to add up to number j
    // dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]]
    int combinationSum4(vector<int>& nums, int target) {
        const int n = nums.size();

        vector<unsigned long long> dp(target + 1, 0);

        dp[0] = 1;
        
        for (int j = 1; j <= target; j++) {
            for (int i = 0; i < n; i++) {
                if (j < nums[i]) {
                    dp[j] = dp[j];
                } else {
                    dp[j] = dp[j] + dp[j - nums[i]];
                }
            }
        }

        return dp[target];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}