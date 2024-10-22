#include <bits/stdc++.h>

using namespace std;

using Slope = pair<int, int>;

namespace std {
    template<>
    struct hash<Slope> {
        size_t operator() (const Slope& slope) const {
            return slope.first ^ slope.second;
        }
    };
}

class Solution {
public:
    // Time: O(n^2) Space: O(n)
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            const vector<int>& pointA = points[i];
            int duplicate = 1;
            unordered_map<Slope, int> record;
            int maxDist = 0;
            for (int j = i + 1; j < n; j++) {
                const vector<int>& pointB = points[j];
                if (pointA == pointB) {
                    duplicate++;
                } else {
                    const Slope slope = getSlope(pointA, pointB);
                    record[slope] += 1;
                    maxDist = max(record[slope], maxDist);
                }
            }
            result = max(result, maxDist + duplicate);
        }

        return result;
    }

    Slope getSlope(const vector<int>& pointA, const vector<int>& pointB) {
        const int dx = pointA[0] - pointB[0];
        const int dy = pointA[1] - pointB[1];

        if (dx == 0) return {pointA[1], 0};
        if (dy == 0) return {0, pointA[0]};

        const int _gcd = gcd(dx, dy);
        return {dx / _gcd, dy / _gcd};
    }

    int gcd(const int x, const int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}