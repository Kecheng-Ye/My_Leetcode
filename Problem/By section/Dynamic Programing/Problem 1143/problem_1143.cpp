#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = max(dp[ i - 1][j], dp[i][j - 1], 1 + dp[i - 1][j - 1] if text1[i] == text2[j])
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);

        int leftTop = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = dp[j + 1];
                dp[j + 1] = max(dp[j], dp[j + 1]);
                if (text1[i] == text2[j]) {
                    dp[j + 1] = max(1 + leftTop, dp[j + 1]);
                }
                leftTop = temp;
            }
            leftTop = 0;
        }

        return dp[n];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}