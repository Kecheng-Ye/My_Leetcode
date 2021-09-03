#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;
        
        // sort(nums.begin(), nums.end());
        // int median = nums[(int)(size / 2)];
        
        int median = findkthbiggest(nums, (int)(size / 2));
        int result = 0;
        
        for(auto& ele : nums) {
            result += abs(ele - median);
        }
        
        return result;
    }
    
    int findkthbiggest(vector<int>& nums, int k) {
        quick_sort_helper(nums, k, 0, nums.size() - 1);
        return nums[k];
    }
    
    void quick_sort_helper(vector<int>& nums, int k, int begin, int end) {
        // Important here
        if(begin >= end) return;
        
        int piviot = partition(nums, begin, end);
        if(piviot == k) {
            return;
        }else if(piviot > k) {
            quick_sort_helper(nums, k, begin, piviot - 1);
        }else{
            quick_sort_helper(nums, k, piviot + 1, end);
        }
    }
    
    int partition(vector<int>& nums, int begin, int end) {
        int i = begin, j = end - 1;
        int target = nums[end];
        
        while(true) {
            while(nums[i] <= target && i < end) {
                i++;
            }
            
            // Important here
            while(nums[j] > target && j > i) {
                j--;
            }
            
            // Important here
            if(i >= j) break;
            
            swap(nums, i, j);
        }
        
        // Important here
        if(i < end) swap(nums, end, i);
        
        return i;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}