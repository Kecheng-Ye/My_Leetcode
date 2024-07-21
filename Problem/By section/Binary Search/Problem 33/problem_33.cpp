#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // find the arr is rotated at which index first
    // then determine which part the target will fall into
    // then do a normal binary search
    // Time: O(logn), Space: O(1)
    // int search(vector<int>& nums, int target) {
    //     const int n = nums.size();
    //     const int rotateIndex = findRotateIndex(nums, n);

    //     if (rotateIndex == 0) {
    //         return binarySearch(nums, target, 0, n - 1);
    //     } else {
    //         return (target > nums[n - 1]) ? binarySearch(nums, target, 0, rotateIndex - 1)
    //                                       : binarySearch(nums, target, rotateIndex, n - 1);
    //     }
    // }

    // int findRotateIndex(const vector<int>& nums, const int n) {
    //     // find rotate index
    //     int i = 0, j = n - 1, mid;

    //     while (i <= j) {
    //         mid = i + (j - i) / 2;
    //         const int left = (mid == 0) ? INT_MAX : nums[mid - 1];
    //         const int right = (mid == n - 1) ? INT_MAX : nums[mid + 1];

    //         if (nums[mid] < left && nums[mid] < right) {
    //             break;
    //         } else if (nums[mid] > nums[j]) {
    //             i = mid + 1;
    //         } else if (nums[mid] < nums[j]) {
    //             j = mid - 1;
    //         }
    //     }

    //     return mid;
    // }

    // int binarySearch(const vector<int>& nums, const int target, const int left, const int right) {
    //     int i = left, j = right, mid;

    //     while (i <= j) {
    //         mid = i + (j - i) / 2;

    //         if (nums[mid] == target) {
    //             return mid;
    //         } else if (nums[mid] > target) {
    //             j = mid - 1;
    //         } else if (nums[mid] < target) {
    //             i = mid + 1;
    //         }
    //     }

    //     return -1;
    // }

    // Time: O(logn) Space: O(1)
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        
        int i = 0, j = n - 1, mid;

        while (i <= j) {
            mid = i + (j - i) / 2;

            if (nums[mid] == target) {
                return mid;
            } 

            // if right part is sorted
            if (nums[mid] < nums[j]) {
                // if the target number is in right part
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            } else { // if right part is sorted
                // if the target number is in left part
                if (nums[mid] > target && target >= nums[i]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}