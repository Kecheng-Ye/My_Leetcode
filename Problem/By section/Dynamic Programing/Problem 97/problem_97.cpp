#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = wether s1[:i] + s2[:j] can form s3[:i + j]
    // Time: O(mn) Space: O(mn)
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.size(), n = s2.size();

        if (m + n != s3.size()) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;


        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}