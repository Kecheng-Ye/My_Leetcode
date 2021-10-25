#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^2), Space: O(n)
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> jobs(n);
        for(int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end(), compare);
        
        vector<int> dp(n + 1, 0);
        dp[0] = jobs[0][2];
        
        for(int i = 1; i < n; i++) {
            int start = jobs[i][0];
            
            for(int j = i - 1; j >= 0; j--) {
                if(jobs[j][1] <= start) {
                    dp[i] = dp[j];
                    break;
                }
            }
            
            dp[i] += jobs[i][2];
            dp[i] = max(dp[i], dp[i - 1]);
        }
        
        return dp[n - 1];
        
    }
    
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        
        return a[1] < b[1];
    }
};


int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}