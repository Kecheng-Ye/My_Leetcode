#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n);
        vector<int> end(n);

        int idx = 0;
        for (const auto& meeting : intervals) {
            start[idx] = meeting[0];
            end[idx] = meeting[1];
            idx++;
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int usedRoom = 0;
        int endPtr = 0;
        for (int i = 0; i < n; i++) {
            // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
            if (start[i] >= end[endPtr]) {
                usedRoom -= 1;
                endPtr += 1;
            }

            // We do this irrespective of whether a room frees up or not.
            // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
            // remain the same in that case. If no room was free, then this would increase used_rooms
            usedRoom += 1;
        }

        return usedRoom;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
