#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(logn)
    int maxOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n == 1) return 0;

        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int result = 0;

        while (i < j) {
            int tempSum = nums[i] + nums[j];
            if (tempSum == k) {
                result++;
                i++;
                j--;
            } else if (tempSum > k) {
                j--;
            } else if (tempSum < k) {
                i++;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}