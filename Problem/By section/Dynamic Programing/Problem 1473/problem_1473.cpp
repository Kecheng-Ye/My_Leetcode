#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int limit = 1e9 + 7;
    const int s = 1;
    
    // dp[i][j][k] = the minimum cost with i group and first j houses and the last one house painted k color 
    // dp[i][j][k] = argmin_x(dp[i - (x == k)][j - 1][x] + cost[j][k])
    // Time: O(TMN^2), Space: O(TMN)
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, limit)));
        
        fill(begin(dp[0][0]), end(dp[0][0]), 0);
            
        for (int k = 1; k <= target; ++k) {
            for (int i = k; i <= m; ++i) {
                // i and i - 1 color on the original record
                const int hi = houses[i - 1];
                const int hj = i >= 2 ? houses[i - 2] : 0;
                // find the potential color range for i and i - 1
                // because if i or i - 1 has already get an color, then we can no longer change it
                const auto& [si, ei] = hi ? tie(hi, hi) : tie(s, n);
                const auto& [sj, ej] = hj ? tie(hj, hj) : tie(s, n);
                
                // try every color combination for i and i - 1
                for (int ci = si; ci <= ei; ++ci) {
                    const int v = ci == hi ? 0 : cost[i - 1][ci - 1];
                    for (int cj = sj; cj <= ej; ++cj) {
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v);
                    }
                }
            }
        }
        
        const int ans = *min_element(begin(dp[target][m]), end(dp[target][m]));
        return ans >= limit ? -1 : ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}