#include <bits/stdc++.h>

using namespace std;
class NumMatrix {
private:
    // prefix_sum[i][j] = sum value from matrix[0 : i][0 : j]
    // Update Rule:
    // prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i][j]
    // Time: O(mn), Space: O(mn)
    vector<vector<int>> prefix_sum;    

public:
    NumMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        prefix_sum = vector<vector<int>>(m + 1, vector<int>(n + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int left = prefix_sum[j][i - 1];
                int up   = prefix_sum[j - 1][i];
                int left_up = prefix_sum[j - 1][i - 1];
                prefix_sum[j][i] = left + up - left_up + grid[j - 1][i - 1];
            }
        }
        
        
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        int left = prefix_sum[x2 + 1][y1];
        int up   = prefix_sum[x1][y2 + 1];
        int left_up = prefix_sum[x1][y1];

        return prefix_sum[x2 + 1][y2 + 1] - left - up + left_up;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}