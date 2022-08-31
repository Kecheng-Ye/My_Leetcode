#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[k][n] = argmax_j(dp[k - 1][j - 1], avg(nums[j : n]))
    // Time: O(kn^2), Space: O(n)
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<int> prefixSum = prefixArray(nums);
        int n = nums.size();

        vector<double> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = (double)prefixSum[i] / (i + 1);
        }

        for (int x = 1; x < k; x++) {
            for (int i = n - 1; i >= x; i--) {
                double result = 0;
                for (int j = x - 1; j < i; j++) {
                    result = max(result, dp[j] + average(prefixSum, j + 1, i));
                }
                dp[i] = result;
            }
        }

        return dp[n - 1];
    }

    vector<int> prefixArray(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        vector<int> prefixSum(n);

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            prefixSum[i] = prefix;
        }

        return prefixSum;
    }

    double average(vector<int>& prefixSum, int start, int end) {
        return (prefixSum[end] - prefixSum[start - 1]) / (double)(end - start + 1);
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
