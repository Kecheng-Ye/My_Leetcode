#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> result;
        
        for(int i = 0; i < n; i++) {
            if(result.empty() || result.back()[1] < intervals[i][0]) {
                result.push_back(intervals[i]);
            }else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
} 