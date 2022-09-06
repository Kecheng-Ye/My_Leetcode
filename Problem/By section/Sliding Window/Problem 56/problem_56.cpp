#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    // Time: O(nlogn), Space: O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;

        sort(intervals.begin(), intervals.end(), compare);

        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];
        vector<vector<int>> result;

        for(int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start > prev_end) {
                result.push_back({prev_start, prev_end});
                prev_start = start;
                prev_end = end;
            } else {
                prev_end = max(prev_end, end);
            }
        }


        result.push_back({prev_start, prev_end});
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
