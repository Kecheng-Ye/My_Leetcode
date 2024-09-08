#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = the maximum value we can get when we land on points[i][j]
    // dp[i][j] = argmax_k(dp[i - 1][k] + points[i][j] + abs(k - j)) where 0 <= k < n
    // Time: O(m * n * n), Space: O(m * n)
    // long long maxPoints(vector<vector<int>>& points) {
    //     const int m = points.size(), n = points[0].size();

    //     vector<vector<long long>> dp(m, vector<long long>(n));
        
    //     for (int i = 0; i < n; i++) {
    //         dp[0][i] = points[0][i];
    //     }

    //     for (int i = 1; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             long long result = 0;
    //             for (int k = 0; k < n; k++) {
    //                 result = max(result, (long long)dp[i - 1][k] + points[i][j] - abs(j - k));
    //             }
    //             dp[i][j] = result;
    //             printf("%d ", dp[i][j]);
    //         }
    //         printf("\n");
    //     }

    //     return *max_element(dp[m - 1].begin(), dp[m - 1].end());
    // }

    // dp[i][j] = the maximum value we can get when we land on points[i][j]
    // dp[i][j] = argmax_k(dp[i - 1][k] + points[i][j] + abs(k - j)) where 0 <= k < n
    // we want to optimize the search k part
    // for me to quickly search argmax_k(dp[i - 1][k] + abs(k - j)), so we have define two other dp arr
    // leftMax[i][j] = the maximum gain for (i - 1) layer when self standing at i, j for range [0, j]
    // rightMax[i][j] = the maximum gain for (i - 1) layer when self standing at i, j for range [j, n]
    // leftMax[i][j] = max(
    //   leftMax[i][j - 1] - 1,  you choose the max from left , the -1 was to add on the position penalty 
    //   dp[i][j]                you choose to stand at j which should cost 0 penalty
    // )
    // then dp[i][j] = max(leftMax[i - 1][j], rightMax[i - 1][j]) + points[i][j]               
    // Time: O(m * n), Space: O(n)
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size(), n = points[0].size();

        vector<long long> dp(n);
        vector<long long> leftMax(n);
        vector<long long> rightMax(n);
        
        for (int i = 0; i < n; i++) {
            dp[i] = points[0][i];
        }

        for (int i = 1; i < m; i++) {
            leftMax[0] = dp[0];
            for (int j = 1; j < n; j++) {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[j]);
            }

            rightMax[n - 1] = dp[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[j]);
            }

            for (int j = 0; j < n; j++) {
                dp[j] = max(leftMax[j], rightMax[j]) + points[i][j];
            }

        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}