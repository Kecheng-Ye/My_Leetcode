#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = the length of longest chain ends with pairs[i]
    // Note: We have to sort it first
    // update rule: 
    // dp[i] = argmax_j (dp[j] + 1)            s.t pairs[j][1] < pairs[i][0]
    vector<int> dp;
    
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    // Time: O(n^2), Space: O(n)
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();
        if(!size) return 0;
        
        sort(pairs.begin(), pairs.end(), compare);
        int result = 1;
        dp = vector<int>(size, 1);
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}