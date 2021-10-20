#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = the unique ways from (0,0) to (i,j)
    // update rule
    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    string a = "abc";
    cout << a.substr(0, 3) << endl;
    return 0;
}