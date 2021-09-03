#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n <= 0) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<int> single_result;
        backtrack(result, single_result, 1, n, k);

        return result;
    }

    bool backtrack(vector<vector<int>>& result, vector<int>& single_result, int start, int target, int num) {
        if(target < 0 || num < 0) {
            return false;
        }else if(target == 0 && num == 0) {
            result.push_back(single_result);
            return true;
        }else {
            bool success = true;

            for(int i = start; i < 10 && success; i++) {
                single_result.push_back(i);

                success = backtrack(result, single_result, i + 1, target - i, num - 1);

                single_result.pop_back();
            }

            return true;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}