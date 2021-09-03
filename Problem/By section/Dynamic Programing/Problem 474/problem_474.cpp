#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j][k] means the largest number of subset when we have first ith strings
    // and with maximum number of j's 0 and k's 1 restriction
    // Update rule: dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - strs[i].zeros][k - strs[i].ones])
    vector<vector<int>> dp;
    
    struct node{
        int zero;
        int one;
    };
    
    // Time: O(m * n * strs.size), Space: O(m * n)
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        if(!size) return 0;
        
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < size; i++) {
            node temp{.zero = 0, .one = 0};
            count(strs[i], temp);
            for(int j = m; j >= temp.zero; j--) {
                for(int k = n; k >= temp.one; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - temp.zero][k - temp.one] + 1); 
                }
            }
        }
        
        return dp[m][n];
    }
    
    void count(string& str, node& temp) {
        for(auto& i : str) {
            if(i == '0') {
                temp.zero ++;
            }else{
                temp.one ++;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}