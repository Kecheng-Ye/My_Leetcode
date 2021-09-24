#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i][j]: can s[0 : i] be matched by p[0 : j]
    // dp[i][j] = (s[i] == p[j]) && dp[i - 1][j - 1]                            if p[j] is a specific character
    // dp[i][j] = dp[i - 1][j - 1]                                              if p[j] is a '.'
    // dp[i][j] = dp[i][j - 2]      || (s[i] == p[j - 1] && dp[i - 1][j])       if p[j] is a '*'
    //          totally ignore *       check if s[i] can be matched by character before * and then if s[0 : i - 1] can be matched by p[0 : j]
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if(!m && !n) return true;
        if(!m || !n) return false;
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        
        // careful initialization
        // because * can be ignored
        for(int i = 0; i < m; i++) {
            if(p[i] == '*') dp[0][i + 1] = dp[0][i - 1];
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(p[j] == '.') {
                    dp[i + 1][j + 1] = dp[i][j];
                }else if(p[j] == '*') {
                    if(j - 1 >= 0) {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];   
                    }
                    bool result = (p[j - 1] == '.') ? true : (p[j - 1] == s[i]);
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] || (result && dp[i][j + 1]);
                }else{
                    dp[i + 1][j + 1] = (s[i] == p[j]) && dp[i][j];
                }
            }
        }
        
        return dp[n][m];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}