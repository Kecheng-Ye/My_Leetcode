#include <bits/stdc++.h>

using namespace std;

#define INVALID '-'

class Solution {
public:
    // Time: O(N! * N) Space: O(N)
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> freq;
        
        for (const char c : s) {
            freq[c] += 1;
        }

        char singleChar = INVALID;
        vector<char> candidates;
        for (const auto& [c, frequency] : freq) {
            if (frequency % 2 == 1) {
                if (singleChar != INVALID) return {};
                singleChar = c;
            }

            for (int i = 0; i < frequency / 2; i++) {
                candidates.push_back(c);
            }
        }

        sort(candidates.begin(), candidates.end());
        
        vector<bool> isVisited(candidates.size());
        string currCombination;
        vector<string> result;
        
        backtrack(candidates, isVisited, currCombination, result, singleChar);

        return result;
    }

    void backtrack(const vector<char>& candidates, vector<bool>& isVisited, string& currCombination, vector<string>& result, const char singleChar) {
        if (currCombination.size() == candidates.size()) {
            string temp = currCombination;
            if (singleChar != INVALID) temp += singleChar;
            temp += string(currCombination.rbegin(), currCombination.rend());
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            if (isVisited[i]) continue;

            if (i > 0 && candidates[i] == candidates[i - 1] && isVisited[i - 1]) continue;

            isVisited[i] = true;
            currCombination += candidates[i];

            backtrack(candidates, isVisited, currCombination, result, singleChar);

            isVisited[i] = false;
            currCombination.pop_back();
        }

    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}