#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return; 
        
        int offset = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                if(i != offset) {
                    swap(nums, i, offset);
                }
                
                offset++;
            }
        }
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