#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first_zero = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (first_zero != i) {
                    swap(nums, first_zero, i);
                }

                first_zero++;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
