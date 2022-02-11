#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> a;
        
        int round = true;
        for(int i = 0; i < m && round; i++) {
            for(int j = 0; j < n && round; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, a);
                    round = false;
                }
            }
        }
        
        int step = 0;
        
        while(true) {
            int size = a.size();
            
            for(int i = 0; i < size; i++) {
                auto node = a.front();
                a.pop();
                int x = node.first, y = node.second;
                
                
                for(const auto& dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] == 2) continue;
                    
                    if(grid[new_x][new_y] == 1) return step;
                    grid[new_x][new_y] = 2;
                    a.push({new_x, new_y});
                }
            }
            
            step++;
        }
        
        return -1;
        
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q) {
        grid[x][y] = 2;
        q.push({x, y});
        
        for(const auto& dir : directions) {
            int new_x = x + dir[0];
            int new_y = y + dir[1];
            
            if(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] != 1) continue;
            
            dfs(grid, new_x, new_y, q);
        }
        
    }
};  

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}