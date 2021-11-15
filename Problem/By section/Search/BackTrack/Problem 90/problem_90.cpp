#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(2^n), Space: O(n)
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         if(nums.size() == 0) return vector<vector<int>>();

//         sort(nums.begin(), nums.end());
//         vector<vector<int>> result;
//         vector<int> single_result;
//         vector<bool> isVisited(nums.size(), false);
        
//         // search on different size of set
//         for(int i = 0; i <= nums.size(); i++) {
//             backtrack(result, nums, single_result, isVisited, 0, i);
//         }

//         return result;
//     }

//     void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& single_result, vector<bool> isVisited, int index, int target_size) {
//         if(single_result.size() == target_size) {
//             result.push_back(single_result);
//         }else{
//             int size = nums.size();

//             for(int i = index; i < size; i++) {
//                 // if we already traverse all the possibility of first duplicate
//                 // then we won't need to explore this node again
//                 if(i > index && nums[i] == nums[i - 1] && !isVisited[i - 1]) continue;

//                 single_result.push_back(nums[i]);
//                 isVisited[i] = true;

//                 backtrack(result, nums, single_result, isVisited, i + 1, target_size);

//                 isVisited[i] = false;
//                 single_result.pop_back();
//             }
//         }
//     }
// };


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> single_result;

        backtrack(result, single_result, nums, 0, nums.size());

        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& single_result, vector<int>& nums, int cur, int target) {
        if(cur == target) {
            result.push_back(single_result);
            return;
        }else{
            // if we meet num which is same as the previous one
            // if we already select previous num, we will definitely select this num
            if(cur > 0 && nums[cur] == nums[cur - 1] && !single_result.empty() && single_result.back() == nums[cur]) {
                single_result.push_back(nums[cur]);
                backtrack(result, single_result, nums, cur + 1, target);
                single_result.pop_back();
            }else{
                backtrack(result, single_result, nums, cur + 1, target);
                
                single_result.push_back(nums[cur]);
                backtrack(result, single_result, nums, cur + 1, target);
                single_result.pop_back();
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}