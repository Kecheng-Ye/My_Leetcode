#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = the minium cost of path from triangle[0][0] to triangle[i][j]
    // Update Rule
    // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]
    // Time: O(mn), Space: O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        
        for(int i = 1; i < n; i++) {
            int m = triangle[i].size();
            for(int j = m - 1; j >= 0; j--) {
                if(j == m - 1) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                }else if(j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        }
        
        return *min_element(dp.begin(), dp.end());
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}