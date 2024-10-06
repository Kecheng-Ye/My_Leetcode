#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int minDiff = INT_MAX;

        int j = 1;
        while (j < timePoints.size()) {
            minDiff = min(
                minDiff,
                timeDiff(timePoints[(j - 1)], timePoints[j])
            );
            j++;
        }

        return min(
            minDiff, 
            oneDayInMin - timeDiff(timePoints[0], timePoints.back())
        );
    }

    const int oneDayInMin = 24 * 60;

    // assume a is always smaller than b
    int timeDiff(const string& a, const string& b) {
        const int hourA = stoi(a.substr(0, 2)), miniuteA = stoi(a.substr(3, 2));
        const int hourB = stoi(b.substr(0, 2)), miniuteB = stoi(b.substr(3, 2));

        return (hourB - hourA) * 60 + (miniuteB - miniuteA);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}