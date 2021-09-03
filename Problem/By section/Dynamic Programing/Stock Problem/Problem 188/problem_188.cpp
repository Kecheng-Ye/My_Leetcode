#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j][k] = the maximal profit that one can receive at day i with j trasanction opeartion restriction
    // and in k state(0 for no stock, 1 for holding the stock)
    // update rule
    // 1. dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
    // meaning if you dont have stock today, you maybe don't have it yesterday or you cell the stock today
    // 2. dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i] - fee)
    // meaning if you have stock today, you maybe have it at yesterday or you buy the stock today
    // we will always return dp[n][k][0], because we will always get more profit if we cell the stock at last day
    vector<vector<vector<int>>> dp;

    // Time: O(N * K), Space: O(N * K)
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(!size) return 0;
        
        if(k >= (size/2)) {
            int dp_i_0 = 0, dp_i_1 = INT_MIN;
            
            for(int i = 0; i < size; i++) {
                int temp = dp_i_0;
                dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = max(dp_i_1, temp - prices[i]);
            }
            
            return dp_i_0;
            
        }else{
            dp = vector<vector<vector<int>>>(size + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
            
            for(int i = 0; i <= size; i++) {
                dp[i][0][1] = INT_MIN; 
            }
            
            for(int i = 0; i <= k; i++) {
                dp[0][i][1] = INT_MIN; 
            }
            
            for(int i = 1; i <= size; i++) {
                for(int j = k; j >= 1; j--) {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
                }
            }
            
            return dp[size][k][0];
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}