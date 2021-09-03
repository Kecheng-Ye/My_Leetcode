#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     int size = nums.size();
    //     if(size == 0) return vector<vector<int>>();
    //     sort(nums.begin(), nums.end());

    //     vector<vector<int>> result;
    //     vector<int> single_result;
    //     backtrack(nums, result, single_result, size);

    //     return result;
    // }

    // void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> single_result, int target_size) {
    //     int cur_size = single_result.size();
    //     if(cur_size == target_size) {
    //         vector<int> temp(single_result);
    //         result.push_back(temp);
    //     }else {
    //         for(int i = 0; i < nums.size(); ++i) {
    //             if((i > 0 && nums[i] == nums[i - 1])) continue;

    //             int new_num = nums[i];

    //             nums.erase(nums.begin() + i);
    //             single_result.push_back(new_num);

    //             backtrack(nums, result, single_result, target_size);

    //             nums.insert(nums.begin() + i, new_num);
    //             single_result.pop_back();
    //         }
    //     }
    // }

    // Time: O(n!), Space: O(n)
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return vector<vector<int>>();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> single_result;
        vector<bool> visited(size, false);
        backtrack(nums, result, single_result, size, visited);

        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int> single_result, int target_size, vector<bool>& visited) {
        int cur_size = single_result.size();
        if(cur_size == target_size) {
            vector<int> temp(single_result);
            result.push_back(temp);
        }else {
            for(int i = 0; i < target_size; ++i) {
                if((i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;

                if(visited[i]) continue;

                visited[i] = true;
                single_result.push_back(nums[i]);

                backtrack(nums, result, single_result, target_size, visited);

                single_result.pop_back();
                visited[i] = true;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}