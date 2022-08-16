#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        long sum = 0;
        long targetSum = 0;
        int left = 0, right = 0;

        while (right < n) {
            sum += nums[right];
            targetSum = (right - left + 1) * (long)nums[right];

            while (targetSum > sum + k) {
                targetSum -= nums[right];
                sum -= nums[left++];
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
