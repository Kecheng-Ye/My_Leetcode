#include <bits/stdc++.h>

using namespace std;

    class Solution {
    public:
        // Time: O(mnlogn), Space: O(mn)
        bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
            int m = maze.size(), n = maze[0].size();

            vector<multiset<int>> horizontal(m);
            vector<multiset<int>> vertical(n);

            for(int i = 0; i < m; i++) {
                horizontal[i].insert(-1);
                horizontal[i].insert(n);
                for(int j = 0; j < n; j++) {
                    if(i == 0) {
                        vertical[j].insert(-1);
                        vertical[j].insert(m);
                    }
                    if(maze[i][j]) {
                        horizontal[i].insert(j);
                        vertical[j].insert(i);
                    }
                }
            }


            queue<vector<int>> q;
            vector<vector<bool>> isVisited(m, vector<bool>(n));
            q.push(start);
            isVisited[start[0]][start[1]] = true;

            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                if(cur[0] == destination[0] && cur[1] == destination[1]) return true;

                explore(cur, horizontal, vertical, q, isVisited, m, n);
            }

            return false;
        }

        void explore(vector<int>& cur, 
                     vector<multiset<int>>& horizontal, vector<multiset<int>>& vertical, 
                     queue<vector<int>>& q,
                     vector<vector<bool>>& isVisited, 
                     int m, int n) {

            multiset<int> row = horizontal[cur[0]];
            multiset<int> col = vertical[cur[1]];

            int left = *(--row.lower_bound(cur[1])) + 1;
            int right = *(row.upper_bound(cur[1])) - 1;
            int down = *(col.upper_bound(cur[0])) - 1;
            int up = *(--col.lower_bound(cur[0])) + 1;

            add_coord(q, isVisited, cur[0], left);
            add_coord(q, isVisited, cur[0], right);
            add_coord(q, isVisited, down, cur[1]);
            add_coord(q, isVisited, up, cur[1]);
        }

        void add_coord(queue<vector<int>>& q,
                       vector<vector<bool>>& isVisited,
                       int x, int y) {

            if(!isVisited[x][y]) {
                q.push({x, y});
                isVisited[x][y] = true;
            }
        }
    };



int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}