#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int left = 0, right = n - 1, mid;
        
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) {
                right = mid;
            }else if(nums[mid] > nums[right]) {
                left = mid + 1;
            }else{
                right -= 1;
            }
        }
        
        return nums[left];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}