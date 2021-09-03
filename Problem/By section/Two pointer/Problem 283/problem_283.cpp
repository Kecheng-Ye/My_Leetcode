#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    void moveZeroes(vector<int>& nums) {
        int first_zero = -1, last_zero = -1;
        int i = 0;
        int size = nums.size();
        while(last_zero != size - 1 && i < size) {
            if(nums[i] != 0) {
                if(first_zero != -1) {
                    swap(nums, first_zero, i);
                    first_zero++;
                    last_zero = i;
                }
            }else{
                if(first_zero == -1) {
                    first_zero = i;
                    last_zero = i;
                }else{
                    last_zero = i;
                } 
            }
            
            i++;
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i]  = nums[j];
        nums[j]  = temp;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}