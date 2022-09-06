#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = 0;
        int result = 0;
        long long curSum = 0;

        while (right < n) {
            long long num1 = (long long)nums[right];
            curSum += num1;
            right++;

            long long targetSum = num1 * (right - left);

            while (targetSum - curSum > k) {
                long long num2 = (long long)nums[left];
                curSum -= num2;
                targetSum -= num1;
                left++;
            }

            result = max(result, right - left);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
