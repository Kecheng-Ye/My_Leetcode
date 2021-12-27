#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Time: O(mn), Space: O(num of path)
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> has_seen;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    string temp = "";
                    DFS(grid, i, j, temp, has_seen, 0);
                }
            }
        }
        
        return has_seen.size();
    }
    
    void DFS(vector<vector<int>>& grid, int x, int y, string& record, unordered_set<string>& has_seen, int lvl) {
        grid[x][y] = 2;
        
        for(int i = 0; i < 4; i++) {
            const auto dir = dirs[i];
            int new_x = x + dir[0], new_y = y + dir[1];
            
            if(new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] != 1) {
                continue; 
            }
            
            record += (char)('0' + i);
            DFS(grid, new_x, new_y, record, has_seen, lvl + 1);
        }
        
        // important here
        // mark as finished
        // in order to distinguish with other path
        record += '0';
        
        if(!lvl && !has_seen.count(record)) {
            has_seen.insert(record);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}