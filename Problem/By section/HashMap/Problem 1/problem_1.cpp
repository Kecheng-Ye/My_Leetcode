#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> need;
        
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            
            if(need.count(target - num)) return vector<int>{need[target - num], i};
            
            need[num] = i;
        }
        
        return vector<int>{};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}