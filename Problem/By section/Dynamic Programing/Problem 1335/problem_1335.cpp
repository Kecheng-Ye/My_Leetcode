#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // dp[i][j] = min difficulty sum can be achieved for arr[1 : i] within i days
    // dp[i][j] = argmin_k(dp[i - 1][k - 1] + max(arr[k : i]))
    // Time: O(n^2 * d), Space: O(n^2)
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        if(d == n) {
            int sum = 0;
            for(const auto& num : jobDifficulty) {
                sum += num;
            }
            
            return sum;
        }
        
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        
        int _max = jobDifficulty[0];
        for(int i = 0; i < n; i++) {
            _max = max(_max, jobDifficulty[i]);
            dp[0][i] = _max;
        }
        
        for(int i = 1; i < d; i++) {
            for(int j = i; j < n; j++) {
                int temp = j;
               _max = jobDifficulty[temp];
                
                while(temp >= i) {
                    _max = max(_max, jobDifficulty[temp]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][temp - 1] + _max);
                    temp--;
                }
            }
        }
        
        return dp[d - 1][n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}