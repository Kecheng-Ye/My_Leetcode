#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    // Time: O(nlogn), Space: O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> result;
        
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            while(j < n) {
                if(end < intervals[j][0]) {
                    break;
                }
                
                end = max(end, intervals[j][1]);
                j++;
            }
            
            result.push_back({start, end});
            i = j - 1;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}