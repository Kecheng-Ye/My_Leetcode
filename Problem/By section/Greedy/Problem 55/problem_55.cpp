#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    bool canJump(vector<int>& nums) {
        int cur_max = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(cur_max < i) return false;
            
            cur_max = max(cur_max, i + nums[i]);
            
            if(cur_max >= n - 1) return true;
        }
        
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}