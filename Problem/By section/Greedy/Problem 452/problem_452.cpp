#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(nlogn), Space: O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 1) return points.size();

        auto compare = [](const vector<int> a, const vector<int> b) {
            return a[1] < b [1];
        };
        sort(points.begin(), points.end(), compare);

        int result = 0;
        int i = 0;
        int prev = INT_MIN;

        while(i < points.size()) {
            if(points[i][0] > prev) {
                prev = points[i][1];
            }else{
                result++;
            }

            i++;
        }

        return points.size() - result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> inputs = {{10, 16}, {2, 10}, {1, 7}, {7, 12}};
    cout << s.findMinArrowShots(inputs) << endl;
}