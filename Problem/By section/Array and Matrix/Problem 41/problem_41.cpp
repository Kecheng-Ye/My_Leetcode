#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int firstMissingPositive(vector<int>& nums) {
        int target = 1, n = nums.size();
        int i = 0;
        
        while(i < n) {
            long long j = (long long)nums[i] - 1;
            
            if(j >= 0 && j < n && nums[i] != nums[j]) {
                swap(nums, i, j);
            }else{
                i++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
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