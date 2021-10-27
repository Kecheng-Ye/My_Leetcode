#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < n; ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}