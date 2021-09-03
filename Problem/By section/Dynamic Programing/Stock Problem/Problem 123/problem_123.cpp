#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_2_0 = 0, dp_i_2_1 = INT_MIN;
        int dp_i_1_0 = 0, dp_i_1_1 = INT_MIN;
        int size = prices.size();
        
        for(int i = 0; i < size; i++) {
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + prices[i]);
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - prices[i]);
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + prices[i]);
            dp_i_1_1 = max(dp_i_1_1, -prices[i]);
        }
        
        return dp_i_2_0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}