#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(2^n), Space: O(n)
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<int> single_result;

        backtrack(result, nums, single_result, 0);

        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& single_result, int index) {
        int size = nums.size();
        
        if(index == size) {
            result.push_back(single_result);
        }else{
            single_result.push_back(nums[index]);

            backtrack(result, nums, single_result, index + 1);

            single_result.pop_back();

            backtrack(result, nums, single_result, index + 1);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}