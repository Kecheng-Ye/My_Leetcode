#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(n)
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums[0] + nums[1];
        
        sort(nums.begin(), nums.end());
        
        int result = INT_MIN;
        int i = 0, j = n - 1;
        
        while(i < j) {
            result = max(result, nums[i++] + nums[j--]);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}