#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;

        while (j < nums.size()) {
            while (j < nums.size() && nums[i] == nums[j]) {
                j++;
            }

            i++;
            if (j < nums.size()) nums[i] = nums[j];
        }

        return i;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}