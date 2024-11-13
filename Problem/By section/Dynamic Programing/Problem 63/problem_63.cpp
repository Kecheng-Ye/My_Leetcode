#include <bits/stdc++.h>

using namespace std;

#define OBSTCALE 1

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        dp[0] = obstacleGrid[0][0] != OBSTCALE;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j ==0) continue;
                if (obstacleGrid[i][j] == OBSTCALE) {
                    dp[j] = 0;
                    continue;
                }
                if (j - 1 >= 0) dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}