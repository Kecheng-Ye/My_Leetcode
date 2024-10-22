#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        // Use cycle sort to place elements
        // at corresponding index to value
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] != nums[correctIdx]) {
                swap(nums[i], nums[correctIdx]);
            } else {
                i++;
            }
        }

        // Any elements not at the index that corresponds to their value are duplicates
        vector<int> duplicates;
        for (i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                duplicates.push_back(nums[i]);
            }
        }

        return duplicates;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}