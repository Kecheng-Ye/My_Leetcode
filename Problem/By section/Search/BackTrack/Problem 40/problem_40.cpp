#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n!), Space: O(n)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        if(size == 0) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> single_result;
        backtrack(result, candidates, single_result, target, 0);

        return result;
    }

    bool backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& single_result, int target, int start_index) {
        if(target == 0) {
            result.push_back(single_result);
            return false;
        }else if(target < 0){
            return true;
        }else{
            bool overflow = false;
            int size = candidates.size();

            for(int i = start_index; i < size && !overflow; i++) {
                if(i > start_index && candidates[i] == candidates[i - 1]) continue;
                single_result.push_back(candidates[i]);

                overflow = backtrack(result, candidates, single_result, target - candidates[i], i + 1);

                single_result.pop_back();
            }

            return false;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}