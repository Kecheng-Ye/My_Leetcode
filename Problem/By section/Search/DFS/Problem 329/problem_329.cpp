#include <bits/stdc++.h>

using namespace std;

class Solution {
    const vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
public:
    // Time: O(mn) Space: O(mn)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        int result = INT_MIN; 
        vector<vector<int>> dp(m, vector<int>(n, -1));

        const function<int(const int, const int)> dfs = [&](const int i, const int j) {
            if (dp[i][j] != -1) return dp[i][j];

            dp[i][j] = 1;

            for (const auto& [xDiff, yDiff] : directions) {
                const int newX = i + xDiff, newY = j + yDiff;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] < matrix[i][j]) {
                    dp[i][j] = max(dp[i][j], 1 + dfs(newX, newY));
                }
            }

            result = max(result, dp[i][j]);
            return dp[i][j];
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1) {
                    dfs(i, j);
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