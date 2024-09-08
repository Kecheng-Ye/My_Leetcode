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

    // Time: O(m * n), Space: O(m * n)
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int m = grid1.size(), n = grid1[0].size();

        vector<vector<bool>> visited2(m, vector<bool>(n, false));

        const auto canMove = [&](const int x, const int y) -> bool {
            return (x >= 0) && (x < m) && (y >= 0) && (y < n) && (grid2[x][y] == 1) && !visited2[x][y];
        };

        const function<bool(const int, const int, bool)> explore = [&](const int x, const int y, bool isSubIsland) -> bool {
            visited2[x][y] = true;
            bool result = isSubIsland;
            if (grid1[x][y] == 1) { 
                result &= true;
            } else {
                result &= false;
            }

            for (const auto& [xDiff, yDiff] : directions) {
                const int newX = x + xDiff, newY = y + yDiff;
                if (canMove(newX, newY)) {
                    result &= explore(newX, newY, result);
                }
            }

            return result;
        };

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !visited2[i][j]) {
                    result += explore(i, j, true);
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