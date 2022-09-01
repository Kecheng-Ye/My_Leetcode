#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
            if (start[i] >= end[endPtr]) {
                usedRoom -= 1;
                endPtr += 1;
            }

            usedRoom += 1;
        }

        return usedRoom;
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
