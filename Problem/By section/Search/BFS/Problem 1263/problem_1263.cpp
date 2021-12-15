#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        state start;
        state end;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'T') {
                    end.b_x = i;
                    end.b_y = j;
                }else if(grid[i][j] == 'B') {
                    start.b_x = i;
                    start.b_y = j;
                }else if(grid[i][j] == 'S') {
                    start.p_x = i;
                    start.p_y = j;
                }
            }
        }

        auto has_path = [&](state cur, const int target_x, const int target_y) {
            vector<bool> is_visited(m * n, 0);

            function<bool(int, int)> DFS = [&](int cur_x, int cur_y) {
                if(cur_x < 0 || cur_x >= m || cur_y < 0 || cur_y >= n || 
                   is_visited[cur_x * n + cur_y] || grid[cur_x][cur_y] == '#') 
                   return false;

                if(cur_x == cur.b_x && cur_y == cur.b_y) return false;

                if(cur_x == target_x && cur_y == target_y) return true;

                is_visited[cur_x * n + cur_y] = true;

                return DFS(cur_x, cur_y - 1) || 
                       DFS(cur_x, cur_y + 1) ||
                       DFS(cur_x - 1, cur_y) ||
                       DFS(cur_x + 1, cur_y );
            };

            return DFS(cur.p_x, cur.p_y);
        };

        queue<state> q;
        unordered_set<int> is_seen;
        int step = 0;

        auto can_push = [&](state cur, int dx, int dy) {
            const int target_x = cur.b_x + dx;
            const int target_y = cur.b_y + dy;

            if( target_x < 0 || target_x >= m || 
                target_y < 0 || target_y >= n || 
                grid[target_x][target_y] == '#') return;

            state new_node(target_x, target_y, cur.b_x, cur.b_y);
            int new_key = new_node.hash();
            if(is_seen.count(new_key)) return;
            
            if(!has_path(cur, cur.b_x - dx, cur.b_y - dy)) return;

            is_seen.insert(new_key);
            q.push(new_node);
        };

        q.push(start);
        is_seen.insert(start.hash());

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; ++i) {
                state cur = q.front();
                q.pop();

                if(cur.b_x == end.b_x && cur.b_y == end.b_y) return step;

                for(const auto dir : directions) {
                    can_push(cur, dir.first, dir.second);
                }
            }

            ++step;
        }

        return -1;
    }

private:
    struct state {
        int b_x;
        int b_y;
        int p_x;
        int p_y;

        state(): b_x(0), b_y(0), p_x(0), p_y(0) {};
        state(int x1, int y1, int x2, int y2): b_x(x1), b_y(y1), p_x(x2), p_y(y2) {};
        int hash() {return ((b_x * 20 + b_y) << 16) | (p_x * 20 + p_y); }
    };
};

// class Solution {
// public:
//     const vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

//     int minPushBox(vector<vector<char>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         state start;
//         state end;

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == 'T') {
//                     end.b_x = i;
//                     end.b_y = j;
//                 }else if(grid[i][j] == 'B') {
//                     start.b_x = i;
//                     start.b_y = j;
//                 }else if(grid[i][j] == 'S') {
//                     start.p_x = i;
//                     start.p_y = j;
//                 }
//             }
//         }

//         auto customized_heurstic = [&](state& cur) {
//             return manhattan_distance(cur.b_x, cur.b_y, end.b_x, cur.b_y);
//         };

//         auto has_path = [&](state& cur, const int target_x, const int target_y) {
//             vector<bool> is_visited(m * n, 0);

//             function<bool(int, int)> DFS = [&](int cur_x, int cur_y) {
//                 if(cur_x < 0 || cur_x >= m || cur_y < 0 || cur_y >= n || 
//                    is_visited[cur_x * n + cur_y] || grid[cur_x][cur_y] == '#') 
//                    return false;

//                 if(cur_x == cur.b_x && cur_y == cur.b_y) return false;

//                 if(cur_x == target_x && cur_y == target_y) return true;

//                 is_visited[cur_x * n + cur_y] = true;

//                 return DFS(cur_x, cur_y - 1) || 
//                        DFS(cur_x, cur_y + 1) ||
//                        DFS(cur_x - 1, cur_y) ||
//                        DFS(cur_x + 1, cur_y );
//             };

//             return DFS(cur.p_x, cur.p_y);
//         };

//         priority_queue<state> q;
//         unordered_set<int> is_seen;

//         auto can_push = [&](state& cur, int dx, int dy) {
//             const int target_x = cur.b_x + dx;
//             const int target_y = cur.b_y + dy;

//             if( target_x < 0 || target_x >= m || 
//                 target_y < 0 || target_y >= n || 
//                 grid[target_x][target_y] == '#') return;

//             state new_node(target_x, target_y, cur.b_x, cur.b_y);
//             int new_key = new_node.hash();
//             if(is_seen.count(new_key)) return;
            
//             if(!has_path(cur, cur.b_x - dx, cur.b_y - dy)) return;

//             new_node.step =  cur.step + 1;
//             new_node.herustic = customized_heurstic(new_node);
//             is_seen.insert(new_key);
//             q.push(new_node);
//         };

//         start.step = 0;
//         start.herustic = customized_heurstic(start);
//         q.push(start);
//         is_seen.insert(start.hash());

//         while(!q.empty()) {
//             int size = q.size();

//             for(int i = 0; i < size; ++i) {
//                 state cur = q.top();
//                 q.pop();

//                 if(cur.b_x == end.b_x && cur.b_y == end.b_y) return cur.step;

//                 for(const auto dir : directions) {
//                     can_push(cur, dir.first, dir.second);
//                 }
//             }
//         }

//         return -1;
//     }

// private:
//     struct state {
//         int b_x;
//         int b_y;
//         int p_x;
//         int p_y;
//         int step;
//         int herustic;

//         state(): b_x(0), b_y(0), p_x(0), p_y(0) {};
//         state(int x1, int y1, int x2, int y2): b_x(x1), b_y(y1), p_x(x2), p_y(y2) {};
//         int hash() {return ((b_x * 20 + b_y) << 16) | (p_x * 20 + p_y); }

//         bool operator<(const state& other) const{
//             return (herustic + step) > (other.herustic + other.step);
//         }
//     };

//     int manhattan_distance(int x1, int y1, int x2, int y2) {
//         return abs(x1 - x2) + abs(y1 - y2);
//     }
// };

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}