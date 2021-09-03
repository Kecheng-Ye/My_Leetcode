#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + price[i])
    // dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 2][j][0] - price[i])

    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN, dp_pre = 0;
        int size = prices.size();

        for(int i = 0; i < size; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_1 + prices[i], dp_i_0);
            dp_i_1 = max(dp_pre - prices[i], dp_i_1);
            dp_pre = temp;
        }

        return dp_i_0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}