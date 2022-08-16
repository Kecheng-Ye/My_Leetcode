#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Our goal is to minimize the difference, so what should i do?

    // Sort the array and then try to make the left adjacent element as maximum and right adjacent element as minimum.

    // So how can we achive this increase all elements in the range [0,i] by k, and decrease all elements in the range [i+1,n-1].

    // So, now potential candidates for the maximum element is arr[i]+k and arr[n-1]-k;
    // and now potential candidates for the minimum element is arr[0]+k and arr[i+1]-k;
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return 0;

        sort(nums.begin(), nums.end());
        int result = nums[n - 1] - nums[0];

        int _min, _max;
        for (int i = 0; i < n - 1; i++) {
            _max = max(nums[i] + k, nums[n - 1] - k);
            _min = min(nums[0] + k, nums[i + 1] - k);

            result = min(result, _max - _min);
        }

        return result;

    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
