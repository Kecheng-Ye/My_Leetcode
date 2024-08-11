#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    
//     int shortestBridge(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         queue<pair<int, int>> a;
        
//         int round = true;
//         for(int i = 0; i < m && round; i++) {
//             for(int j = 0; j < n && round; j++) {
//                 if(grid[i][j] == 1) {
//                     dfs(grid, i, j, a);
//                     round = false;
//                 }
//             }
//         }
        
//         int step = 0;
        
//         while(true) {
//             int size = a.size();
            
//             for(int i = 0; i < size; i++) {
//                 auto node = a.front();
//                 a.pop();
//                 int x = node.first, y = node.second;
                
                
//                 for(const auto& dir : directions) {
//                     int new_x = x + dir[0];
//                     int new_y = y + dir[1];

//                     if(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] == 2) continue;
                    
//                     if(grid[new_x][new_y] == 1) return step;
//                     grid[new_x][new_y] = 2;
//                     a.push({new_x, new_y});
//                 }
//             }
            
//             step++;
//         }
        
//         return -1;
        
//     }
    
//     void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q) {
//         grid[x][y] = 2;
//         q.push({x, y});
        
//         for(const auto& dir : directions) {
//             int new_x = x + dir[0];
//             int new_y = y + dir[1];
            
//             if(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] != 1) continue;
            
//             dfs(grid, new_x, new_y, q);
//         }
        
//     }
// };  

class Solution {
public:
    const vector<pair<int, int>> diretions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    // Bidirectional BFS
    // Time: O(mn/2), Space: O(mn/2)
    int shortestBridge(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        bool foundOne = false;

        int step = 0;

        queue<pair<int, int>> q1;
        int tag1 = 2;

        queue<pair<int, int>> q2;
        int tag2 = 3;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!foundOne) {
                        findIsland(grid, i, j, tag1, q1);
                        foundOne = true;
                    } else {
                        findIsland(grid, i, j, tag2, q2);
                    }
                }
            }
        }

        while (!q1.empty() || !q2.empty()) {
            int levelSize = q1.size();

            while (levelSize--) {
                const auto [x, y] = q1.front(); q1.pop();

                for (const auto& [xDiff, yDiff] : diretions) {
                    int newX = x + xDiff;
                    int newY = y + yDiff;
                    
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == tag1) {
                        continue;
                    }

                    if (grid[newX][newY] != 0) return step;

                    grid[newX][newY] = tag1;
                    q1.push({newX, newY});
                }
            }

            step++;
            swap(q1, q2);
            swap(tag1, tag2);
        }

        return step;
    }

    void findIsland(vector<vector<int>>& grid, const int x, const int y, const int tag, queue<pair<int, int>>& q) {
        const int m = grid.size(), n = grid[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == tag || grid[x][y] != 1) {
            return;
        }

        grid[x][y] = tag;
        q.push({x, y});

        for (const auto [xDiff, yDiff] : diretions) {
            findIsland(grid, x + xDiff, y + yDiff, tag, q);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}