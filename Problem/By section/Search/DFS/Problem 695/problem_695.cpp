#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Time: O(n), Space: O(1)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int size = grid.size();
        if(size == 0) return 0;

        int result = 0;

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    int temp_result = 0;
                    dfs(grid, i, j, temp_result);
                    result = max(result, temp_result);
                }
            }
        }

        return result;

    }

    void dfs(vector<vector<int>>& grid, int x, int y, int& result) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) return;

        result++;
        // remeber to mark as visited
        grid[x][y] = 2;

        for(auto& direction : directions) {
            dfs(grid, x + direction[0], y + direction[1], result);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}