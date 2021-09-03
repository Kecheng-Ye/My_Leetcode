#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dp;
    
    int change(int amount, vector<int>& coins) {
        if(!amount) return 1;
        int size = coins.size();
        if(!size) return 0;
        
        dp = vector<int>(amount + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < size; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}