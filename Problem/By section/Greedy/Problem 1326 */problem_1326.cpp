#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Same as Problem 45
    // We just have to first transform the center range to furtherest[left] = right convention
    // Time: O(n), Space: O(1)
    int minTaps(int n, vector<int>& ranges) {
        // the furthest point the water can jump from point i
        vector<int> jumps(n+1, 0);
        for(int i = 0; i <= n; ++i) {
            int l = max(i-ranges[i], 0);
            int r = min(i+ranges[i], n);
            jumps[l] = max(jumps[l], r-l);
        }

        int currentReach = 0, endPosition = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(i > currentReach) { // cannot reach this point
                return -1;
            }
            // find the furthest point you can reach at this point
            currentReach = max(i + jumps[i], currentReach);
            // we should always choose the point that is closer to the start point
            if(i == endPosition) {
                endPosition = currentReach;
                ++cnt;
            }
        }
        if(endPosition >= n) {
            return cnt;
        } else {
            return -1;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
