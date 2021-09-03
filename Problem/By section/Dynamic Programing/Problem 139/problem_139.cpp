#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j] = with first i words in wordDict can be break the s[0 : j]
    // Update Rule
    // dp[i][j] = dp[i - 1][j] || dp[i][j - wordDict[i]]
    vector<bool> dp;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        dp = vector<bool>(size + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= size; i++) {
            // since word break should follow certain sequence
            // we will put this iteration inside 
            for(int j = 0; j < wordDict.size(); j++) {
                int word_size = wordDict[j].size();
                if(word_size <= i && s.substr((i - word_size), word_size) == wordDict[j]) {
                    dp[i] = dp[i] || dp[i - word_size];
                }
            }
        }
        
        return dp[size];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}