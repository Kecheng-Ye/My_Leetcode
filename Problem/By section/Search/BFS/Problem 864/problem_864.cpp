#include <bits/stdc++.h>

using namespace std;

#define extract_X(state) (cur_state & 0xFF0000) >> 16
#define extract_Y(state) (cur_state & 0xFF00) >> 8
#define extract_key(state) cur_state & 0xFF
#define generate_state(x, y, key) ((x << 16) | (y << 8) | key)

class Solution {
public:
    const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    // Time: O((mn * 2^6)^4), Space: O((mn * 2^6)^4)
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        if(!m) return -1;
        int n = grid[0].size();
        
        // one state is ((x << 16) | (y << 8) | key)
        int full_key = 0;
        int start_x = -1;
        int start_y = -1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(is_key(grid, i, j)) {
                    full_key |= (1 << (grid[i][j] - 'a'));
                }else if(grid[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
        queue<unsigned int> q;
        q.push(generate_state(start_x, start_y, 0));
        unordered_set<unsigned int> is_visited;
        int step = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int cur_state = q.front();
                q.pop();
                
                int cur_x = extract_X(cur_state), cur_y = extract_Y(cur_state), key = extract_key(cur_state);
                if(key == full_key) return step;
                
                for(const auto& dir : dirs) {
                    int next_x = cur_x + dir[0], next_y = cur_y + dir[1];
                    int new_key = key;
                    
                    if(!can_go_through(grid, next_x, next_y, m, n)) continue;
                    
                    if(is_lock(grid, next_x, next_y) && !(key & (1 << (grid[next_x][next_y] - 'A')))) continue;
                    
                    if(is_key(grid, next_x, next_y)) {
                        new_key |= (1 << (grid[next_x][next_y] - 'a'));
                    }
                    
                    int new_state = generate_state(next_x, next_y, new_key);
                    
                    if(is_visited.count(new_state)) continue;
                    
                    is_visited.insert(new_state);
                    q.push(new_state);
                }
            }
            
            step++;
        }
        
        return -1;
    }
    
    bool can_go_through(vector<string>& grid, int x, int y, int m, int n) {
        return !(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#'); 
    }
    
    bool is_key(vector<string>& grid, int x, int y) {
        return (grid[x][y] - 'a') >= 0 && (grid[x][y] - 'a') < 6;
    }
    
    bool is_lock(vector<string>& grid, int x, int y) {
        return (grid[x][y] - 'A') >= 0 && (grid[x][y] - 'A') < 6;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}