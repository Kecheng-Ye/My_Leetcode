#include <bits/stdc++.h>

using namespace std;

#define X 0
#define Y 1

class Solution {
public:
    // Time: O(n^2) Space: O(logn)
    int numberOfPairs(vector<vector<int>>& points) {
        // sort by x coordinate, use y coordinate to break tie
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b){
            if (a[X] == b[X]) return a[Y] > b[Y];
            return a[X] < b[X];
        });
        const int n = points.size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            int currMax = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                if (points[i][Y] < points[j][Y]) continue;

                // means the sqr between points[i] and points[j] will include currMax
                if (currMax >= points[j][Y]) continue;

                count++;
                currMax = points[j][Y];
            }
        }

        return count;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}