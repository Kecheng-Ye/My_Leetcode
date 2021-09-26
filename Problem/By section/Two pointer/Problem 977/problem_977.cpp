#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {nums[0] * nums[0]};
        
        int neg, pos = 0;
        int idx = 0;
        vector<int> result(n, 0);
        
        for(; pos < n && nums[pos] < 0; pos++)
            ;
        neg = pos - 1;
        
        while(idx < n) {
            int target;
            if(neg < 0) {
                target = nums[pos] * nums[pos++];
            }else if(pos >= n) {
                target = nums[neg] * nums[neg--];
            }else if(abs(nums[neg]) > nums[pos]) {
                target = nums[pos] * nums[pos++];
            }else{
                target = nums[neg] * nums[neg--];
            }
            
            result[idx++] = target;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}