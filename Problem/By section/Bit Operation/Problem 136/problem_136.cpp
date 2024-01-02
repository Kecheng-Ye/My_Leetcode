#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        int n = nums.size();
        if(n == 1) return result;
        
        for(int i = 1; i < n; i++) {
            result ^= nums[i];
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}