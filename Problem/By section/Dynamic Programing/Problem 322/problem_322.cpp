#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = the minimum number of coin with first i choices of coins to make up j dollar
    // Update rule
    // dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1) 
    // vector<vector<int>> dp;
    
    // m = coins.size, n = amount
    // Time: O(m * n), Space: O(m * n)
    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0) return 0;
        
    //     int size = coins.size();
    //     if(!size) return 0;
        
    //     dp = vector<vector<int>>(size + 1, vector<int>(amount + 1, INT_MAX));
        
    //     for(int i = 0; i <= size; i++) {
    //         dp[i][0] = 0;
    //     }
        
    //     for(int i = 1; i <= size; i++) {
    //         for(int j = 1; j <= amount; j++) {
    //             if(j - coins[i - 1] >= 0) {
    //                 int use_coin = (dp[i][j - coins[i - 1]] == INT_MAX) ? INT_MAX : dp[i][j - coins[i - 1]] + 1;
    //                 dp[i][j] = min(use_coin, dp[i - 1][j]);
    //             }else{
    //                 dp[i][j] = dp[i - 1][j];
    //             }
    //         }
    //     }

    //     return (dp[size][amount] == INT_MAX) ? -1 : dp[size][amount];
    // }

    // compress it into 1-d array
    vector<int> dp;

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int size = coins.size();
        if(!size) return 0;

        dp = vector<int>(amount + 1, 0);

        for(int i = 0; i < size; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                if(j - coins[i] == 0) {
                    dp[j] = 1;
                }else if(dp[j] == 0 && dp[j - coins[i]] != 0){ // if we cannot make j without i'th coin
                    dp[j] = dp[j - coins[i]] + 1;
                }else if(dp[j - coins[i]] != 0){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[amount] == 0 ? -1 : dp[amount];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> input = {1};
    cout << s.coinChange(input, 0) << endl;
    return 0;
}