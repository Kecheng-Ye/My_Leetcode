#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = the minimum distance from mat[i][j] to nearest 0
    // dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i][j + 1], dp[i + 1][j]) + 1
    //                left          up            right         down
    // Time: O(n), Space: O(n)                  
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, m + n + 1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dp[i][j] = 0;
                }else{
                    int left = (j > 0) ? dp[i][j - 1] + 1 : INT_MAX;
                    int up = (i > 0) ? dp[i - 1][j] + 1 : INT_MAX;
                    dp[i][j] = min(dp[i][j], left);
                    dp[i][j] = min(dp[i][j], up);
                }
            }
        }
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(mat[i][j] == 0) {
                    dp[i][j] = 0;
                }else{
                    int right = (j < n - 1) ? dp[i][j + 1] + 1 : INT_MAX;
                    int down = (i < m - 1) ? dp[i + 1][j] + 1 : INT_MAX;
                    dp[i][j] = min(dp[i][j], right);
                    dp[i][j] = min(dp[i][j], down);
                }
            }
        }
        
        return dp;
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}