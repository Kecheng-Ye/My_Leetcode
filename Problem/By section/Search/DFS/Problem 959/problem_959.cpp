#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    // Time: O(9mn), Space: O(9mn)
    int regionsBySlashes(vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> extendedGrid = extendRegion(grid);

        int result = 0;
        const function<void(const int, const int)> explore = [&](const int x, const int y) {
            if (x < 0 || x >= 3 * m || y < 0 || y >= 3 * n || extendedGrid[x][y] != 0) return;

            extendedGrid[x][y] = 1;

            for (const auto& [xDiff, yDiff] : directions) {
                explore(x + xDiff, y + yDiff);
            }

            return;
        };

        for (int i = 0; i < 3 * m; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (extendedGrid[i][j] == 0) {
                    result++;
                    explore(i, j);
                }
            }
        }

        return result;
    }

    vector<vector<int>> extendRegion(const vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> result(3 * m, vector<int>(3 * n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    result[(i + 1) * 3 - 1][3 * j] = -1;
                    result[(i + 1) * 3 - 2][3 * j + 1] = -1;
                    result[i * 3][3 * j + 2] = -1;
                } else if (grid[i][j] == '\\') {
                    result[3 * i][3 * j] = -1;
                    result[3 * i + 1][3 * j + 1] = -1;
                    result[3 * i + 2][3 * j + 2] = -1;
                }
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}