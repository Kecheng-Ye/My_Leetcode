#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = can the subset of nums[0, j] achieve a sum of i
    // update rule
    // dp[i][j] = dp[i][j - 1] || dp[i - nums[j]][j - 1]
    // which means we will either use the last element to achieve i or not use the last one to achieve i
    // vector<vector<bool>> dp;
    
    // Time: O(n * m), Space: O(n * m)
    // bool canPartition(vector<int>& nums) {
    //     int size = nums.size();
    //     if(!size) return 0;
        
    //     int sum = 0;
    //     for(int i : nums) {
    //         sum += i;
    //     }
    //     if(sum % 2 != 0) return 0;
    //     sum /= 2;
        
    //     dp = vector<vector<bool>>(size + 1, vector<bool>(sum + 1, false));
    //     for(int i = 0; i <= size; i++) {
    //         dp[i][0] = true;
    //     }
        
    //     for(int i = 1; i <= size; i++) {
    //         for(int j = 1; j <= sum; j++) {
    //             if(j - nums[i - 1] >= 0) {
    //                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
    //             }else{
    //                 dp[i][j] = dp[i - 1][j];
    //             }
                
    //             if(j == sum && dp[i][j]) return true;
    //         }
    //     }
        
    //     return dp[size][sum];
    // }

    // compressed version of dp
    // since previously dp[i][j] = dp[i][j - 1] || dp[i - nums[j]][j - 1]
    // it only concerns with dp[i - 1]
    // so we can compress it into one dimension
    vector<bool> dp;
    
    // Time: O(n * m), Space: O(m)
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        
        int sum = 0;
        for(int i : nums) {
            sum += i;
        }
        if(sum % 2 != 0) return 0;
        sum /= 2;
        
        dp = vector<bool>(sum + 1, false);
        dp[0] = true;
        
        for(int i = 0; i < size; i++) {
            for(int j = sum; j >= 0; j--) {
                if(j - nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                
                if(j == sum && dp[j]) return true;
            }
        }
        

        
        return dp[sum];
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}