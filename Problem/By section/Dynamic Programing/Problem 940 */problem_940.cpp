#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    
    // dp[i] = number of distinct subsequency of s[0 : i]
    // dp[i] = dp[i - 1] * 2 - dp[prev_char[s[i]] - 1]
    // e.g for string s: `baca`
    // the second a will double all subsequence for `bac`, 
    // surly it will double the subsequence for 'ba', which will generate duplicates
    // so we have to consider all duplicates before the previous 'a' character
    // Time: O(n), Space: O(n)
    // Space can be further optimize when our prev_seen store the actual value of dp[prev_char[s[i]] - 1]
    // instead of the index
    int distinctSubseqII(string s) {
        int n = s.size();
        if(n <= 1) return n;
        
        vector<int> dp(n + 1, 0);
        vector<int> prev_seen(26, -1);
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) % mod;
            
            if(prev_seen[s[i - 1] - 'a'] >= 0) {
                dp[i] -= dp[prev_seen[s[i - 1] - 'a']];
            }
            
            dp[i] %= mod;
            prev_seen[s[i - 1] - 'a'] = i - 1;
        }
        
        return (dp[n] - 1) > 0 ? dp[n] - 1 : (dp[n] - 1) + mod;
    }


};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}