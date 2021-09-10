#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // Time: O(m * n), Space: O(m * n)
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        int num_oranges = 0;
        int num_rotten_oranges = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    num_oranges++;
                    
                    if(grid[i][j] == 2) {
                        q.push({i, j});
                        num_rotten_oranges++;
                    }
                } 
            }
        }
        
        while(!q.empty()) {
            if(num_rotten_oranges == num_oranges) return ans;
            
            int level = q.size();
            
            for(int i = 0; i < level; i++) {
                auto new_rotten = q.front();
                q.pop();
                
                for(const auto& direction : directions) {
                    int x = new_rotten.first + direction.first;
                    int y = new_rotten.second + direction.second;
                    
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    
                    grid[x][y] = 2;
                    num_rotten_oranges++;
                    q.push({x, y});
                }
            }
            
            ans++;
            
        }
        
        return (num_rotten_oranges == num_oranges) ? 0 : -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}