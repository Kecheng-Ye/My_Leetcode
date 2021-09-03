#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = the length of longest subsequence ends with nums[i]
    // update rule
    // dp[i] = argmax_j (dp[j] + 1)        s.t nums[j] < nums[i]
    vector<int> dp;
    
    // Time: O(n^2), Space: O(n)
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        
        dp = vector<int>(size, 1);
        int result = 1;
        
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] >= nums[i]) continue;
                
                dp[i] = max(dp[i], dp[j] + 1);
            }
            
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}