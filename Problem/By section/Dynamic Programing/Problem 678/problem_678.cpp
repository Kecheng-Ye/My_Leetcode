#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // dp[i][j]: Is s[i : j] a valid string
    // dp[i][j] = dp[i + 1][j - 1]          if s[i] in "(*" and s[j] in "*)"
    //         or dp[i][k] && dp[k + 1][j]  
    // Time: O(n^3), Space: O(n^2)
    bool checkValidString(string s) {
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return checkValidString(s, 0, n - 1);
    }
    
private:
    vector<vector<int>> dp;
    const unordered_set<char> left = {'*', '('};
    const unordered_set<char> right = {'*', ')'};
    
    bool checkValidString(string& s, int i, int j) {
        if(i > j) return true;
        
        if(i == j) return dp[i][i] = (s[i] == '*');
        
        if(dp[i][j] >= 0) return dp[i][j];
        
        if(left.count(s[i]) && right.count(s[j]) && checkValidString(s, i + 1, j - 1)) {
            return dp[i][j] = true;
        }
        
        for(int k = i; k < j; k++) {
            if(checkValidString(s, i, k) && checkValidString(s, k + 1, j)) {
                return dp[i][j] = true;
            }
        }
        
        return dp[i][j] = false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}