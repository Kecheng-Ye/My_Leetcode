#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(log(n)), Space: O(1)
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size() == 0) return vector<int>{-1, -1};
    
//         int left_bound = bin_search_left(nums, target);
//         int right_bound = bin_search_right(nums, target);

//         return vector<int>{left_bound, right_bound};
//     }

//     int bin_search_left(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int mid;

//         while(left <= right) {
//             mid = left + (right - left) / 2;

//             if(nums[mid] == target) {
//                 right = mid - 1;
//             }else if(nums[mid] > target) {
//                 right = mid - 1;
//             }else if(nums[mid] < target) {
//                 left = mid + 1;
//             }
//         }

//         if(left > nums.size() - 1 || nums[left] != target) return -1;

//         return left;
//     }

//     int bin_search_right(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int mid;

//         while(left <= right) {
//             mid = left + (right - left) / 2;

//             if(nums[mid] == target) {
//                 left = mid + 1;
//             }else if(nums[mid] > target) {
//                 right = mid - 1;
//             }else if(nums[mid] < target) {
//                 left = mid + 1;
//             }
//         }

//         if(right < 0 || nums[right] != target) return -1;

//         return right;
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return {-1, -1};
        
        int left = binary_left(nums, target, 0, n);
        if(left == -1) return {-1, -1};
        int right = binary_right(nums, target, left, n);
        return {left, right};
    }
    
    int binary_left(vector<int>& nums, int target, int i, int j) {
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] < target) {
                i = mid + 1;
            }else if(nums[mid] == target){ // in this case, j is still in the range of mid
                j = mid;
            }else if(nums[mid] > target) {
                j = mid;
            }
        }
        
        // so we will return nums[left] anyway
        if (i == nums.size()) return -1;
        
        return (nums[i] == target) ? i : -1;
    }
    
    int binary_right(vector<int>& nums, int target, int i, int j) {
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] > target) {
                j = mid;
            }else if(nums[mid] == target){ // in this case, j surpass mid
                i = mid + 1;
            }else if(nums[mid] < target) {
                i = mid + 1;
            }
        }
        
        // in this case we will return nums[left - 1]
        return i - 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}