#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Time: O(n), Space: O(n)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!mat[i][j]) {
                    q.push({i, j});
                    is_visited[i][j] = true;
                }
            }
        }
        
        int step = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto coord = q.front();
                q.pop();
                int x = coord.first, y = coord.second;
        
                result[x][y] = step;
                
                for(const auto& dir : directions) {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;
                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || is_visited[new_x][new_y]) continue;
                    
                    is_visited[new_x][new_y] = true; // very important here, incase to prevent one cell being visited twice
                    q.push({new_x, new_y});
                }
            }
            
            
            ++step;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}