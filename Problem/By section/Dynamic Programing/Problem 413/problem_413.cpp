#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = the number of Arithmetic sequence ending with A[i]
    // update rule
    // dp[i] = dp[i - 1] + 1
    // copying all the combination of previous dp[i - 1] and plus 1 for forming a bigger sequence
    vector<int> dp;

    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) return 0;

        int result = 0;
        dp = vector<int>(size, 0);
        int prev_diff = nums[1] - nums[0];

        for(int i = 2; i < size; i ++) {
            int temp = 0;
            int diff = nums[i] - nums[i -1];

            if(diff == prev_diff) temp = 1 + dp[i - 1];

            prev_diff = diff;
            dp[i] = temp;
            result += temp; 
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    int i;
    // cout << (cin >> i) << endl;
    return 0;
}