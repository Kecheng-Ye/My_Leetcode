#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const string& a, const string& b) {
        return a.size() < b.size();
    }
    
    // dp[i] = the longest strchain ends with words[i]
    // dp[i] = argmax_j(dp[(words[i] - jth character)] + 1)
    // Time: O(NlogN + N * L^2), Space: O(N)
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n == 1) return n;
        
        // need to sort it first in order to be able to do bottom up
        sort(words.begin(), words.end(), compare);
        
        unordered_map<string, int> dp;
        int _max = 0;
        
        for(int i = 0; i < n; i++){
            string cur = words[i];
            int size = words[i].size();
            dp[cur] = 1;
                
            for(int j = 0; j < size; j++) {
                string temp = cur.substr(0, j) + cur.substr(j + 1, size - j - 1);
                if(dp.count(temp)) {
                    dp[cur] = max(dp[cur], dp[temp] + 1);
                }
            }
            
            _max = max(_max, dp[cur]); 
        }
        
        return _max;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}