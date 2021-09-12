#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return size;
        
        // down = the length of the longest subsequence ends with nums[i] and nums[i - 1] > nums[i]
        // up = the length of the longest subsequence ends with nums[i] and nums[i - 1] < nums[i]
        int up = 1;
        int down = 1;
        
        for(int i = 1; i < size; i++) {
            if(nums[i] > nums[i - 1]) {
                up = down + 1;
            }else if(nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        
        return max(down, up);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}