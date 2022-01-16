#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Time: O(n^2), Space: O(n)
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> clsuter(2, 0);
        int color = 2;
        int result = 0;
        
        // color each island into different color
        // and record each color island's size into `clsuter`
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    int cur = DFS(grid, i, j, color++);
                    result = max(result, cur);
                    clsuter.push_back(cur);   
                }
            }
        }
        
        // the reason we should use a hash set is to prevent that one 0 cell connect to same group of 1
        // eg. [[0,1],[1,1]]
        // answer should be 1 + 3, instead of 1 + 3 + 3
        unordered_set<int> diff_cluster;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    diff_cluster.clear();
                    for(const auto& [x, y] : dirs) {
                        int new_x = i + x;
                        int new_y = j + y;
                        
                        if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= n || grid[new_x][new_y] == 0) continue;
                        diff_cluster.insert(grid[new_x][new_y]);
                    }
                    
                    int cur_res = 1;
                    
                    for(const int c : diff_cluster) {
                        cur_res += clsuter[c];
                    }
                    
                    result = max(result, cur_res);
                }
            }
        }
        
        return result;
    }
    
    int DFS(vector<vector<int>>& grid, int x, int y, int color) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid.size() || grid[x][y] != 1) return 0;
        
        grid[x][y] = color;
        
        int result = 1 + DFS(grid, x - 1, y, color)
                       + DFS(grid, x + 1, y, color)
                       + DFS(grid, x, y - 1, color)
                       + DFS(grid, x, y + 1, color);
            
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}