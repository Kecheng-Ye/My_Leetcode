#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void square_list(int n, vector<int>& lst) {
        int diff = 3;
        int square = 1;
        while (square <= n) {
            lst.push_back(square);
            square += diff;
            diff += 2;
        }
    }

public:
    // dp[i] = least number of perfect square numbers that sums up to i
    // update rule
    // dp[i] = argmin_j (dp[i - j^2] + 1)
    vector<int> dp;

    // Time: O(n * sqrt(n)), Space: O(n)    
    int numSquares(int n) {
        if(n == 1) return 1;
        
        dp = vector<int>(n + 1, INT_MAX);
        vector<int> sqr_lst;
        square_list(n, sqr_lst);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(auto& j : sqr_lst){
                if(i < j) break;
                
                dp[i] = min(dp[i], 1 + dp[i - j]);
            }
        }
        
        return dp[n];
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}