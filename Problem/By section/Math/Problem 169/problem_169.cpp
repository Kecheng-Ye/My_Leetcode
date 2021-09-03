#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() / 2];
    // }
    
    // Time: O(n), Space: O(1)
    int majorityElement(vector<int>& nums) {
        int count = 0, result = nums[0];
        
        for(auto& ele: nums) {
            result = (count == 0) ? ele : result;
            (ele == result) ? count++ : count--;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}