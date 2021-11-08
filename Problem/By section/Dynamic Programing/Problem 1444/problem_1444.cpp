#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int limit = 1e9 + 7;
    
    // dp[i][j][k] = total way of spliting pizza[i : m][j : n] with k cuts such that each piece has a topping
    // dp[i][j][k] = sum(hasApple(i, j, x, n - 1) * dp[x + 1][j][k - 1]) + sum(hasApple(i, j, m - 1, y) * dp[i][y + 1][k - 1])
    //               number of ways to cut horizontally                    number of ways to cut vertically
    // Time: O(mnk * (m + n)), Space: O(mnk)
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prefix_sum[i + 1][j + 1] = (pizza[i][j] == 'A') + 
                                            prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - 
                                            prefix_sum[i][j];
            }
        }
        
        
        auto hasApple = [&](int x, int y, int i, int j) {
            int up = prefix_sum[x][j + 1];
            int left = prefix_sum[i + 1][y];
            int up_left = prefix_sum[x][y];
            
            
            return (int)((prefix_sum[i + 1][j + 1] - up - left + up_left) > 0);
        };
        
        vector<vector<vector<int>>> memorization(m, vector<vector<int>>(n, vector<int>(k, -1)));
        
        function<int(int, int ,int)> dp = [&](int i, int j, int k){
            if(k == 0) return hasApple(i, j, m - 1, n - 1);
            int& ans = memorization[i][j][k];
            if(ans != -1) return ans;
            ans = 0;
            
            for(int x = i; x < m - 1; x++) {
                auto temp = hasApple(i, j, x, n - 1);
                ans = (ans + temp * dp(x + 1, j, k - 1)) % limit;
            }
            
            for(int y = j; y < n - 1; y++) {
                auto temp = hasApple(i, j, m - 1, y);
                ans = (ans + temp * dp(i, y + 1, k - 1)) % limit;
            }
            
            return ans;
        };
        
        return dp(0, 0, k - 1);
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}