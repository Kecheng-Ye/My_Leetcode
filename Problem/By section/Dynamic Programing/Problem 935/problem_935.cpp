#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> keyboard = {{1, 2, 3}, 
                                          {4, 5, 6}, 
                                          {7, 8, 9}, 
                                          {-1, 0, -1}};
    
    const vector<vector<int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    const int mod = 1e9 + 7;
    
    // dp[i][j] = number of distinct phone numbers with length i and ends with key j
    // dp[i][j] = sum(dp[i - 1][k] where k can jump to j)
    int knightDialer(int n) {
        // come_from[i] = list of all possible keys that can jump to i
        vector<unordered_set<int>> come_from(10);
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(keyboard[i][j] < 0) continue;
                
                for(const auto& dir : directions) {
                    int new_x = i + dir[0], new_y = j + dir[1];
                    if(new_x < 0 || new_x >= 4 || new_y < 0 || new_y >= 3 || keyboard[new_x][new_y] < 0) continue;
                    
                    come_from[keyboard[new_x][new_y]].insert(keyboard[i][j]);
                }
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        
        for(int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        
        int result = 0;
        
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 10; j++) {
                for(const auto& start : come_from[j]) {
                    dp[i][j] = ((dp[i][j] % mod) + dp[i - 1][start]) % mod;
                }
            
                if(i == n) result = ((result % mod) + dp[i][j]) % mod;
            }
        }
        
        return (n == 1) ? 10 : result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}