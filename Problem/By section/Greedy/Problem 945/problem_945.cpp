#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
       // Time: O(n), Space: O(n) 
//     int minIncrementForUnique(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0];
        
//         unordered_set<int> record;
//         int move = 0;
//         for(int num : nums) {
//             int temp = num;
//             while(record.count(temp)) {
//                 temp++;
//                 move++;
//             }
//             record.insert(temp);
//         }
        
//         return move;
//     }
    
    // Time: O(nlogn), Space: O(n)
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        sort(nums.begin(), nums.end());
        int move = 0;
        int cur_min = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] <= cur_min) {
                move += (cur_min + 1 - nums[i]);
                cur_min++;
            }else{
                cur_min = nums[i]; 
            }
        }
        return move;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}