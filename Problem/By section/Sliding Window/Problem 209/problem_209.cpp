#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, result = INT_MAX;
        int n = nums.size();
        int cur_sum = 0;

        while (right < n) {
            cur_sum += nums[right++];

            while (cur_sum >= target) {
                result = min(result, right - left);
                cur_sum -= nums[left++];
            }
        }

        return (result == INT_MAX) ? 0 : result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
