#include <bits/stdc++.h>

using namespace std;

#define START 0
#define END 1

class Solution {
public:
    // Use binary search to find the insert index
    // then try to merge the newInterval
    // Time: O(n), Space: O(1)
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     int n = intervals.size();
    //     if(!n) return {newInterval};
        
    //     int i = 0, j = n;
        
    //     while(i < j) {
    //         int mid = i + (j - i) / 2;
    //         if(intervals[mid][1] > newInterval[1]) {
    //             j = mid;
    //         }else{
    //             i = mid + 1;
    //         }
    //     }
        
    //     int start = (i == n) ? i - 1 : i;
    //     while(start >= 0 && intervals[start][1] >= newInterval[0]) {
    //         newInterval[0] = min(newInterval[0], intervals[start][0]);
    //         start--;
    //     }
        
        
    //     int end = i;
    //     while(end < n && intervals[end][0] <= newInterval[1]) {
    //         newInterval[1] = max(newInterval[1], intervals[end][1]);
    //         end++;
    //     }
        
    //     intervals.erase(intervals.begin() + start + 1, intervals.begin() + end);
    //     intervals.insert(intervals.begin() + start + 1, newInterval);
    //     return intervals;
        
    // }

    // Time: O(n), Space: O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(!n) return {newInterval};
        
        vector<vector<int>> result;
        for(auto& interval : intervals) {
            if(newInterval[END] < interval[START]) {
                result.push_back(newInterval);
                newInterval = interval;
            }else if(newInterval[START] > interval[END]) {
                result.push_back(interval);
            }else{
                newInterval[START] = min(newInterval[START], interval[START]);
                newInterval[END] = max(newInterval[END], interval[END]);
            }
        }

        result.push_back(newInterval);
        return result;

    }
    
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}