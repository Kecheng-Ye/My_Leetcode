#include <bits/stdc++.h>

using namespace std;

using Coordinate = pair<int, int>;

namespace std {

template<>
struct hash<Coordinate> {
    size_t operator() (const Coordinate& coord) const {
        return coord.first ^ coord.second;
    }
};

}

class Solution {
    const vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    using State = pair<Coordinate, int>;
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int m = moveTime.size(), n = moveTime[0].size();
        const auto compare = [&](const State& a, const State& b) {
            return a.second > b.second;
        };
        const auto isValid = [&](const Coordinate& coord) {
            return (
                coord.first >= 0 &&
                coord.first < m &&
                coord.second >= 0 &&
                coord.second < n
            );
        };

        priority_queue<State, vector<State>, decltype(compare)> pq(compare);
        unordered_map<Coordinate, int> distMap;
        const Coordinate targetNode{m - 1, n - 1};

        pq.push({{0, 0}, 0});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distMap[{i, j}] = INT_MAX;
            }
        }
        distMap[{0, 0}] = 0;

        while (!pq.empty()) {
            const auto [coord, dist] = pq.top(); pq.pop();
            if (distMap[coord] < dist) continue;
            if (coord == targetNode) return dist;

            for (const auto& [xDiff, yDiff] : directions) {
                const Coordinate newCoord{coord.first + xDiff, coord.second + yDiff};
                
                if (!isValid(newCoord)) continue;

                const int newDist = 1 + dist + 
                    max(0, moveTime[newCoord.first][newCoord.second] - dist);
                
                if (newDist < distMap[newCoord]) {
                    distMap[newCoord] = newDist;
                    pq.push({newCoord, newDist});
                }
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}