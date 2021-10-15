#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(!n) return {newInterval};
        
        int i = 0, j = n;
        
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(intervals[mid][1] > newInterval[1]) {
                j = mid;
            }else{
                i = mid + 1;
            }
        }
        
        int start = (i == n) ? i - 1 : i;
        while(start >= 0 && intervals[start][1] >= newInterval[0]) {
            newInterval[0] = min(newInterval[0], intervals[start][0]);
            start--;
        }
        
        
        int end = i;
        while(end < n && intervals[end][0] <= newInterval[1]) {
            newInterval[1] = max(newInterval[1], intervals[end][1]);
            end++;
        }
        
        intervals.erase(intervals.begin() + start + 1, intervals.begin() + end);
        intervals.insert(intervals.begin() + start + 1, newInterval);
        return intervals;
        
    }
    
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}