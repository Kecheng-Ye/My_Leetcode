#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '*') {
                    is_visited[i][j] = true;
                    q.push({i, j});
                    goto end;
                }
            }
        }
        
end:
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                
                if(grid[x][y] == '#') {
                    return result;
                }
                
                for(const auto& dir : directions) {
                    const int new_x = x + dir.first;
                    const int new_y = y + dir.second;
                    
                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == 'X' || is_visited[new_x][new_y]) 
                        continue;
                    
                    is_visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
            
            result++;
        }
        
        
        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}