#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int n = candidates.size();

        if (n == 1 && target != candidates[0]) return {};

        vector<vector<int>> result;
        vector<int> currComb;

        sort(candidates.begin(), candidates.end());
        
        const function<void(const int, const int)> backtrack = [&](const int idx, const int rest) {
            if (rest == 0) {
                result.push_back(currComb);
                return;
            }

            if (rest < 0) {
                return;
            }

            for (int i = idx; i < n; i++) {
                if (candidates[i] > rest) {
                    break;
                }

                currComb.push_back(candidates[i]);
                backtrack(i, rest - candidates[i]);
                currComb.pop_back();
            }

            return;
        };

        backtrack(0, target);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}