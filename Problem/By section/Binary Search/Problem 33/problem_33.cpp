#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // find the arr is rotated at which index first
    // then determine which part the target will fall into
    // then do a normal binary search
    // Time: O(logn), Space: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n - 1;
        int rotate_idx;

        if(nums[l] < nums[r]) {
            rotate_idx = 0;
        }else{
            while(l < r) {
                int mid = l + (r - l) / 2;

                if(nums[mid] > nums[r]) {
                    l = mid + 1;
                }else if(nums[mid] < nums[r]) {
                    r = mid;
                }
            }
            
            rotate_idx = l;
        }
        
        l = 0;
        r = n - 1;
        
        if(rotate_idx == 0) {
            return binary_search(nums, 0, n, target);
        }else{
            if(target > nums[r]) {
                return binary_search(nums, 0, rotate_idx, target);
            }else{
                return binary_search(nums, rotate_idx, n, target);
            }
        }

        return -1;        
    }
    
    int binary_search(vector<int>& nums, int left, int right, int target) {
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
               return mid; 
            }else if(nums[mid] > target) {
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}