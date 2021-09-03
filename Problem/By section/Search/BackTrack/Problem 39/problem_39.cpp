#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return vector<vector<int>>();

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> singel_result;

        backtrack(result, candidates, singel_result, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& singel_result, int target, int start_index) {
        if(target < 0) {
            return;
        }else if(target == 0) {
            result.push_back(singel_result);
        }else{
            int size = candidates.size();

            for(int i = start_index; i < size; i++) {
                singel_result.push_back(candidates[i]);

                backtrack(result, candidates, singel_result, target - candidates[i], i);

                singel_result.pop_back();
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}