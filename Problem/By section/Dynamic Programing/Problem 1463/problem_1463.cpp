#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j][k]: the maximum number of cherries that two robots can pick when robot 1 at grid[i][j] and robot 2 at grid[i][k]
    // dp[i][j][k] = argmax_{x, y}(dp[i][j + x][k + y]) when -1 <= x, y <= 1
    // Time: O(mn^2), Space: O(mn^2)
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        int result = INT_MIN;
        
        auto update = [&](int i, int j, int k) {
            int before_1, before_2;
            
            for(int x = -1; x <= 1; x++) {
                before_1 = j + x;
                if(before_1 < 0 || before_1 >= n) continue;
                
                for(int y = -1; y <= 1; y++) {
                    before_2 = k + y;
                    if(before_2 < 0 || before_2 >= n || dp[i - 1][before_1][before_2] == -1) continue;
                    
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][before_1][before_2]);
                }
            }
            
            if(dp[i][j][k] != -1) {
                dp[i][j][k] += (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
                result = max(result, dp[i][j][k]);   
            }
        };
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    update(i, j, k);
                }
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}