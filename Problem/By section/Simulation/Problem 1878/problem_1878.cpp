#include <bits/stdc++.h>

using namespace std;

#define LIMIT 3

class Solution {
public:
    // Time: O((mn)^2) Space: O(1)
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        const auto canFormRhombus = [&](const int x, const int y, const int radius) -> bool {
            return (
                x - radius >= 0 &&
                x + radius < m &&
                y - radius >= 0 &&
                y + radius < n
            );
        };

        const auto rhombusSum = [&](const int x, const int y, const int radius) -> int {
            if (radius == 0) return grid[x][y];

            const int xMin = x - radius;
            const int xMax = x + radius;
            const int yMin = y - radius;
            const int yMax = y + radius;

            int sum = 0;
            int i = xMin, j = y;
            // top -> left
            while (j > yMin) {
                sum += grid[i++][j--];
            }

            // left -> bot
            while (i < xMax) {
                sum += grid[i++][j++];
            }

            // bot -> right
            while (j < yMax) {
                sum += grid[i--][j++];
            }

            // bot -> top
            while (i > xMin) {
                sum += grid[i--][j--];
            }

            return sum;
        };

        set<int> result;
        const int rhombusRadiusMax = min(m, n) / 2 + min(m, n) % 2;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int radius = 0; radius <= rhombusRadiusMax; radius++) {
                    if (canFormRhombus(i, j, radius)) {
                        result.insert(rhombusSum(i, j, radius));
                    }

                    if (result.size() > LIMIT) {
                        result.erase(result.begin());
                    }    
                }
                
            }
        }
        
        return {result.rbegin(), result.rend()};
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}