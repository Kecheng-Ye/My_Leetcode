#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // num = [a, b, c, d]
    // prefix = [1, a, ab, abc]
    // suffix = [bcd, cd, d, 1]
    // prefix * suffix = answer
    // Time: O(n), Space: O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        
        int n = nums.size();
        int left = 1;
        // prefix
        for(int i = 1; i < n; i++) {
            left *= nums[i - 1];
            result[i] *= left;
        }
        
        // suffix
        int right = 1;
        for(int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            result[i] *= right;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}