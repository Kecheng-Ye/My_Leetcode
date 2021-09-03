#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // transition function
    // dp[i] = dp[i - 1] + dp[i - 2]
    vector<int> dp;

    // Time: O(n), Space: O(n)
    int climbStairs(int n) {
        dp = vector<int>(n + 1, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i ++) {
            dp[i] += dp[i - 1];

            if(i - 2 >= 0) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}