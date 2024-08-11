#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(mnlogn), Space: O(mn)
//     bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
//         int m = maze.size(), n = maze[0].size();

//         vector<multiset<int>> horizontal(m);
//         vector<multiset<int>> vertical(n);

//         for(int i = 0; i < m; i++) {
//             horizontal[i].insert(-1);
//             horizontal[i].insert(n);
//             for(int j = 0; j < n; j++) {
//                 if(i == 0) {
//                     vertical[j].insert(-1);
//                     vertical[j].insert(m);
//                 }
//                 if(maze[i][j]) {
//                     horizontal[i].insert(j);
//                     vertical[j].insert(i);
//                 }
//             }
//         }


//         queue<vector<int>> q;
//         vector<vector<bool>> isVisited(m, vector<bool>(n));
//         q.push(start);
//         isVisited[start[0]][start[1]] = true;

//         while(!q.empty()) {
//             auto cur = q.front();
//             q.pop();

//             if(cur[0] == destination[0] && cur[1] == destination[1]) return true;

//             explore(cur, horizontal, vertical, q, isVisited, m, n);
//         }

//         return false;
//     }

//     void explore(vector<int>& cur, 
//                     vector<multiset<int>>& horizontal, vector<multiset<int>>& vertical, 
//                     queue<vector<int>>& q,
//                     vector<vector<bool>>& isVisited, 
//                     int m, int n) {

//         multiset<int> row = horizontal[cur[0]];
//         multiset<int> col = vertical[cur[1]];

//         int left = *(--row.lower_bound(cur[1])) + 1;
//         int right = *(row.upper_bound(cur[1])) - 1;
//         int down = *(col.upper_bound(cur[0])) - 1;
//         int up = *(--col.lower_bound(cur[0])) + 1;

//         add_coord(q, isVisited, cur[0], left);
//         add_coord(q, isVisited, cur[0], right);
//         add_coord(q, isVisited, down, cur[1]);
//         add_coord(q, isVisited, up, cur[1]);
//     }

//     void add_coord(queue<vector<int>>& q,
//                     vector<vector<bool>>& isVisited,
//                     int x, int y) {

//         if(!isVisited[x][y]) {
//             q.push({x, y});
//             isVisited[x][y] = true;
//         }
//     }
// };

// Hash function  
struct hashFunction 
{ 
  long operator()(const pair<int, int> &x) const
  { 
    return x.first ^ x.second;
  } 
}; 

template <>
struct hash<pair<int, int>>
{
  size_t operator()(const pair<int, int>& k) const
  {
    const auto& hashFunc = hash<int>();

    return ((hashFunc(k.first) ^ (hashFunc(k.second))));
  }
};

namespace std
{
    pair<int, int>& operator+= (pair<int, int>& lhs, const pair<int, int>& rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
}

class Solution {
public:
    const vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const pair<int, int> startLoc = {start[0], start[1]};
        const pair<int, int> destLoc = {destination[0], destination[1]};
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>> isVisited;

        q.push(startLoc);
        isVisited.insert(startLoc);


        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                const auto curr = q.front(); q.pop();
                
                if (curr == destLoc) return true;

                for (const auto newLoc : tryKick(maze, curr)) {
                    if (!isVisited.count(newLoc)) {
                        q.push(newLoc);
                        isVisited.insert(newLoc);
                    }
                }
            } 
        }

        return false;
    }

private:
    vector<pair<int, int>> tryKick(const vector<vector<int>>& maze, const pair<int, int>& currLoc) {
        vector<pair<int, int>> result;

        for (const auto& dir : directions) {
            const pair<int, int> newLoc = kickOneDirection(maze, currLoc, dir);
            if (newLoc != currLoc) {
                result.push_back(newLoc);
            }
        }

        return result;
    }

    pair<int, int> kickOneDirection(const vector<vector<int>>& maze, const pair<int, int>& currLoc, const pair<int, int>& direction) {
        const auto hitBoundary = [&](const pair<int, int>& loc) -> bool {
            return (loc.first < 0 || loc.first >= maze.size() || loc.second < 0 || loc.second >= maze[0].size());
        };

        const auto hitWall = [&](const pair<int, int>& loc) -> bool {
            const pair<int, int> newLoc = {loc.first + direction.first, loc.second + direction.second};
            if (hitBoundary(newLoc)) return true;
            return maze[loc.first + direction.first][loc.second + direction.second] == 1;
        };
        
        pair<int, int> curr = currLoc;
        
        while (!hitWall(curr)) {
            curr.first += direction.first;
            curr.second += direction.second;
        }

        return curr;
    }
};


int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}