#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return;

        int minIdx = n - 1;
        int j = n - 1;
        
        // find j such that nums[j - 1] < nums[j]
        while (j >= 1) {
            const int currNum = nums[j];
            const int prevNum = nums[j - 1];

            if (prevNum < currNum) {
                break;
            }
            j--;
        }

        if (j == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find such k within nums[j+1 : ] and it is smallest among all number bigger than  nums[j - 1]
        int closest = j;
        while (closest < n && nums[closest] > nums[j - 1]) {
            closest++;
        }

        swap(*(nums.begin() + j - 1), *(nums.begin() + closest - 1));
        reverse(nums.begin() + j, nums.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}