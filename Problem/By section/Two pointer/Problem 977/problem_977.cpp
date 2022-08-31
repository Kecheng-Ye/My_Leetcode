#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);
        int idx = n - 1;

        int i = 0, j = n - 1;

        while (i <= j) {
            int left_square = pow(nums[i], 2);
            int right_square = pow(nums[j], 2);

            if (left_square >= right_square) {
                result[idx--] = left_square;
                i ++;
            } else {
                result[idx--] = right_square;
                j --;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
