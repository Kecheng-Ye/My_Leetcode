#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = the maximum product of i
    // update rule
    // dp[i] = argmax_j (dp[i - j] * dp[j])
    // Note here: if j <= 4, dp[j] <= j
    // Also we can cut half of the searching space because
    // eg. dp[2] * dp[4] = dp[4] * dp[2]
    vector<int> dp;
    
    // Time: O(n^2), Space: O(n)
    int integerBreak(int n) {
        dp = vector<int>(n, INT_MIN);
        dp[0] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= (int)(i/2); j++) {
                int one_part = max(dp[j - 1], j);
                int another_part = max(dp[i - j - 1], i - j);
                
                dp[i - 1] = max(dp[i - 1], one_part * another_part);
            }
        }
        
        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}