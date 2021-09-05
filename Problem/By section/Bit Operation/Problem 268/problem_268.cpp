#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: o(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = n;
        for(int i = 0; i < n; i++) {
            result ^= i;
            result ^= nums[i];
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}