#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = 2 + dp[i + 1][j - 1]              if s[i] == s[j]
    //          = max(dp[i + 1][j], dp[i][j - 1])   else
    // Time: O(n^2), Space: O(n^2)
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (!n) return 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int j = 0; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + ((j > i + 1) ? dp[i + 1][j - 1] : 0);
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
