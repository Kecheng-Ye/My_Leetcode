#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(logn)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return find_majority(nums, 0, n - 1).first;
    }
    
    pair<int, int> find_majority(vector<int>& nums, int start, int end) {
        if(start == end) return {nums[start], 1};
        
        int mid = start + (end - start) / 2;
        auto left_major = find_majority(nums, start, mid);
        auto right_major = find_majority(nums, mid + 1, end);
        
        if(left_major.first == right_major.first) return {left_major.first, left_major.second + right_major.second};
        
        if(left_major.second > right_major.second) {
            return {left_major.first, left_major.second + count(nums.begin() + 1 + mid, nums.begin() + end + 1, left_major.first)};
        }else{
            return {right_major.first, right_major.second + count(nums.begin() + start, nums.begin() + mid + 1, right_major.first)};
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}