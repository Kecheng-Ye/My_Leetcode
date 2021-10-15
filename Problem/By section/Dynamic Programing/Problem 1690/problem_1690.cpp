#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^2), Space: O(n^2)
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        if(n == 1) return stones[0];
        
        vector<int> prefix_sum(n, stones[0]);
        
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + stones[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(i == j) {
                    dp[i][j] = 0;
                }else{
                    int left = prefix_sum[j] - prefix_sum[i] - dp[i + 1][j];
                    int right = prefix_sum[j - 1] - ((i == 0) ? 0 : prefix_sum[i - 1]) - dp[i][j - 1];
                    
                    dp[i][j] = max(left, right);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}