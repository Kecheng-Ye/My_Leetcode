#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int numOfFlip = 0;
        int result = 0;

        while (right < n) {
            int num1 = nums[right];
            if (!num1) numOfFlip++;
            right++;

            while (numOfFlip > k) {
                int num2 = nums[left];
                if (!num2) numOfFlip--;
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
