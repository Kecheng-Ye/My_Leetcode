#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // // dp[i][j] = the least distance from grid[0][0] to grid[i][j]
    // // update rule
    // // dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    // // because the grid[i][j] can only come from the left cell or the upper cell
    // vector<vector<int>> dp;

    // // Time: O(m * n), Space: O(m * n)
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     if(!m) return 0;

    //     int n = grid[0].size();
    //     dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));

    //     dp[0][0] = grid[0][0];
    //     for(int i = 1; i < m; i++){
    //         dp[i][0] = dp[i - 1][0] + grid[i][0];
    //     }

    //     for(int i = 1; i < n; i++){
    //         dp[0][i] = dp[0][i - 1] + grid[0][i];
    //     }

    //     for(int i = 1; i < m; i++) {
    //         for(int j = 1; j < n; j++) {
    //             dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    //         }
    //     }

    //     return dp[m - 1][n - 1];
    // }

    // Can be compress into 1d array
    // Since for dp[i][j], we only need dp[i - 1][j] or dp[i][j - 1]
    vector<int> dp;

    // Time: O(m * n), Space: O(m * n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;

        int n = grid[0].size();
        dp = vector<int>(n, INT_MAX);

        // important!!! 
        // if we set it to be grid[0][0], then dp[0][0] will be 2 * grid[0][0] during iteration
        dp[0] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // first should be j == 0
                // because i == 0 condition will cause potential out of bound
                if(j == 0) {
                    dp[j] = dp[j];
                }else if(i == 0){
                    dp[j] = dp[j - 1];
                }else{
                    dp[j] = min(dp[j - 1], dp[j]);
                }

                dp[j] = dp[j] + grid[i][j];
            }
        }

        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}