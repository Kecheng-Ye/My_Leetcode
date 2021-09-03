#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(log(n)), Space: O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>{-1, -1};
    
        int left_bound = bin_search_left(nums, target);
        int right_bound = bin_search_right(nums, target);

        return vector<int>{left_bound, right_bound};
    }

    int bin_search_left(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                right = mid - 1;
            }else if(nums[mid] > target) {
                right = mid - 1;
            }else if(nums[mid] < target) {
                left = mid + 1;
            }
        }

        if(left > nums.size() - 1 || nums[left] != target) return -1;

        return left;
    }

    int bin_search_right(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                left = mid + 1;
            }else if(nums[mid] > target) {
                right = mid - 1;
            }else if(nums[mid] < target) {
                left = mid + 1;
            }
        }

        if(right < 0 || nums[right] != target) return -1;

        return right;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}