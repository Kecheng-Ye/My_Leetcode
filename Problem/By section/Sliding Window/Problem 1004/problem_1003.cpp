#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right;
        int n = nums.size();
        for (right = 0; right < n; right++) {
            // If we included a zero in the window we reduce the value of k.
            // Since k is the maximum zeros allowed in a window.
            if (nums[right] == 0) {
                k--;
            }
            // A negative k denotes we have consumed all allowed flips and window has
            // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
            if (k < 0) {
                // If the left element to be thrown out is zero we increase k.
                k += 1 - nums[left];
                left++;
            }
        }
        return right - left;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}