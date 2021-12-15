#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // dp[i] = the length of longest subsequence ends with nums[i]
//     // update rule
//     // dp[i] = argmax_j (dp[j] + 1)        s.t nums[j] < nums[i]
//     vector<int> dp;
    
//     // Time: O(n^2), Space: O(n)
//     int lengthOfLIS(vector<int>& nums) {
//         int size = nums.size();
//         if(!size) return 0;
        
//         dp = vector<int>(size, 1);
//         int result = 1;
        
//         for(int i = 1; i < size; i++) {
//             for(int j = 0; j < i; j++) {
//                 if(nums[j] >= nums[i]) continue;
                
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
            
//             result = max(result, dp[i]);
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    // optimized solution
    // dp[i] = the smallest element that ends an increasing subsequence of length i + 1

    // Time: O(nlogn), Space: O(1)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        vector<int> dp;
        
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end()) {
                dp.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        
        return dp.size();
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}