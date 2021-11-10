#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int i = 0, j = n;
        while(i < j) {
            int mid = i + (j - i) / 2;
            
            int left = (mid == 0) ? INT_MIN : nums[mid - 1];
            int right = (mid == n - 1) ? INT_MIN : nums[mid + 1];
            
            if(nums[mid] > left && nums[mid] > right) {
                return mid;
            }else if(left >= right) {
                j = mid;
            }else {
                i = mid + 1;
            }
        }
        
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}