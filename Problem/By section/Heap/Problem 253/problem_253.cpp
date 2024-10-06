#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (const auto& interval : intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
