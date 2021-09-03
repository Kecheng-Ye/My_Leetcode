#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        // Important here, we only cares the end part 
        // counter example: {{1, 100}, {2, 3}, {4, 5}}
        auto compare = [](const vector<int> a, const vector<int> b){
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), compare);

        int result = 0;
        int prev = INT_MIN;
        for(auto interval : intervals) {
            if(interval[0] >= prev) {
                prev = interval[1];
            }else {
                result++;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> input = {{1, 100}, {2, 3}, {4, 5}};
    cout << s.eraseOverlapIntervals(input) << endl;
}