#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    // int findDuplicate(vector<int>& nums) {
    //     while(nums[0] != nums[nums[0]])
    //         swap(nums, 0, nums[0]);
        
    //     return -1;
    // }
    
    // void swap(vector<int>& nums, int i, int j) {
    //     int temp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = temp;
    // }
    
    // Time: O(nlogn), Space: O(1)
    // int findDuplicate(vector<int>& nums) {
    //     // 'low' and 'high' represent the range of values of the target
    //     int low = 1, high = nums.size();
    //     int duplicate = -1;
    //     while (low <= high) {
    //         int cur = (low + high) / 2;
            
    //         int cnt = 0;
    //         for(int& num : nums) {
    //             if(num <= cur) cnt++;
    //         }

    //         if (cnt > cur) { 
    //             duplicate = cur;
    //             high = cur - 1;
    //         } else {
    //             low = cur + 1;
    //         }
    //     }

    //     return duplicate;
    // }

    // Time: O(n), Space: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}