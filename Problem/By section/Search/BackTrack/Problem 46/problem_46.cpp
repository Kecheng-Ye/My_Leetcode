#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        vector<bool> visited(size, false);
        vector<int> single_result;

        backtrack(nums, visited, result, single_result, size);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& visited, vector<vector<int>>& result, vector<int>& single_result, int num_left) {
        if(num_left == 0) {
            vector<int> temp(single_result);
            result.push_back(temp);
        }else {
            int size = nums.size();

            for(int i = 0; i < size; ++i) {
                if(visited[i]) continue;

                single_result.push_back(nums[i]);
                visited[i] = true;

                backtrack(nums, visited, result, single_result, num_left - 1);

                single_result.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}