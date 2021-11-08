#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        
        for(int i = 0; i < min(4, n); i++) {
            min_diff = min(nums[n - 4 + i] - nums[i], min_diff);
        }
        
        return min_diff;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}