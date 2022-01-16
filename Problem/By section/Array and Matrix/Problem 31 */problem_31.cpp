#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int j = n - 2;
        
        while(j >= 0) {
            if(nums[j] < nums[j + 1]) break;
            
            j--;
        }
        
        if(j == -1) {
            reverse(nums.begin(), nums.end());
        }else{
            int target = -1;
            
            for(int i = j + 1; i < n; i++) {
                if(nums[i] > nums[j]) {
                    if(target < 0) {
                        target = i;
                    }else{
                        target = (nums[i] <= nums[target]) ? i : target; 
                    }
                }
            }
            
            int temp = nums[j];
            nums[j] = nums[target];
            nums[target] = temp;
            
            reverse(nums.begin() + j + 1, nums.end());
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}