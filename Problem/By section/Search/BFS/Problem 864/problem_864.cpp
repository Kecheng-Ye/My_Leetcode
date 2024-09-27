#include <bits/stdc++.h>
#include <utility>

using namespace std;

// #define extract_X(state) (cur_state & 0xFF0000) >> 16
// #define extract_Y(state) (cur_state & 0xFF00) >> 8
// #define extract_key(state) cur_state & 0xFF
// #define generate_state(x, y, key) ((x << 16) | (y << 8) | key)

// class Solution {
// public:
//     const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
//     // Time: O((mn * 2^6)^4), Space: O((mn * 2^6)^4)
//     int shortestPathAllKeys(vector<string>& grid) {
//         int m = grid.size();
//         if(!m) return -1;
//         int n = grid[0].size();
        
//         // one state is ((x << 16) | (y << 8) | key)
//         int full_key = 0;
//         int start_x = -1;
//         int start_y = -1;
        
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(is_key(grid, i, j)) {
//                     full_key |= (1 << (grid[i][j] - 'a'));
//                 }else if(grid[i][j] == '@') {
//                     start_x = i;
//                     start_y = j;
//                 }
//             }
//         }
        
//         queue<unsigned int> q;
//         q.push(generate_state(start_x, start_y, 0));
//         unordered_set<unsigned int> is_visited;
//         int step = 0;
        
//         while(!q.empty()) {
//             int size = q.size();
            
//             while(size--) {
//                 int cur_state = q.front();
//                 q.pop();
                
//                 int cur_x = extract_X(cur_state), cur_y = extract_Y(cur_state), key = extract_key(cur_state);
//                 if(key == full_key) return step;
                
//                 for(const auto& dir : dirs) {
//                     int next_x = cur_x + dir[0], next_y = cur_y + dir[1];
//                     int new_key = key;
                    
//                     if(!can_go_through(grid, next_x, next_y, m, n)) continue;
                    
//                     if(is_lock(grid, next_x, next_y) && !(key & (1 << (grid[next_x][next_y] - 'A')))) continue;
                    
//                     if(is_key(grid, next_x, next_y)) {
//                         new_key |= (1 << (grid[next_x][next_y] - 'a'));
//                     }
                    
//                     int new_state = generate_state(next_x, next_y, new_key);
                    
//                     if(is_visited.count(new_state)) continue;
                    
//                     is_visited.insert(new_state);
//                     q.push(new_state);
//                 }
//             }
            
//             step++;
//         }
        
//         return -1;
//     }
    
//     bool can_go_through(vector<string>& grid, int x, int y, int m, int n) {
//         return !(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#'); 
//     }
    
//     bool is_key(vector<string>& grid, int x, int y) {
//         return (grid[x][y] - 'a') >= 0 && (grid[x][y] - 'a') < 6;
//     }
    
//     bool is_lock(vector<string>& grid, int x, int y) {
//         return (grid[x][y] - 'A') >= 0 && (grid[x][y] - 'A') < 6;
//     }
// };

#define isSelf(target) (target == '@')
#define isWall(target) (target == '#')
#define isKey(target) ((target - 'a') >= 0 && (target - 'a') < 6)
#define isLock(target) ((target - 'A') >= 0 && (target - 'A') < 6)
#define encodeKey(target) (1 << (target - 'a'))
#define encodeLock(target) (1 << (target - 'A'))

struct State {
public:
    State(): x(0), y(0), keys(0) {}

    State(const uint8_t _x, const uint8_t _y, const uint8_t _keys): x(_x), y(_y), keys(_keys) {}

    State(const State& other) {
        x = other.x;
        y = other.y;
        keys = other.keys;
    }

    bool hasKey(const char targetLock) const {
        return (keys & encodeLock(targetLock)) != 0;
    }

    void addKey(const char target) {
        keys |= encodeKey(target);
    }

    bool hasAllKeys(const uint8_t targetKey) const {
        return keys == targetKey;
    }

    State move(const pair<int, int>& direction) const {
        State newState = *this;
        newState.x += direction.first;
        newState.y += direction.second;
        return newState;
    }

    bool operator== (const State &other) const {
        return x == other.x &&
               y == other.y &&
               keys == other.keys;
    }

    State operator+ (const pair<int, int>& direction) const {
        return {static_cast<uint8_t>(x + direction.first), static_cast<uint8_t>(y + direction.second), keys};
    }

    uint8_t x;
    uint8_t y;
    uint8_t keys;
};

template<>
struct hash<State> {
    size_t operator() (const State& s) const {
        return (s.x << 16) | (s.y << 8) | (s.keys);
    }
};

class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

public:
    // Time: O((mn * 2^6)^4), Space: O((mn * 2^6)^4)
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        const auto [initState, targetKeys] = getInitState(grid);
        queue<State> q;
        unordered_set<State> isVisited;
        int step = 0;

        const auto cantMove = [&](const State& curr, const pair<int, int>& direction) -> bool {
            int newX = curr.x + direction.first, newY = curr.y + direction.second;
            return (newX < 0)  ||
                   (newX >= m) ||
                   (newY < 0)  ||
                   (newY >= n) ||
                   (isWall(grid[newX][newY])) ||
                   (isLock(grid[newX][newY]) && !curr.hasKey(grid[newX][newY]));
        };

        q.push(initState);
        isVisited.insert(initState);

        while (!q.empty()) {
            int levelSize = q.size();
            step++;

            while (levelSize--) {
                const State curr = q.front(); q.pop();

                if (curr.hasAllKeys(targetKeys)) return step - 1;

                for (const auto& direction : directions) {
                    if (cantMove(curr, direction)) continue;

                    State newState = curr + direction;

                    if (isKey(grid[newState.x][newState.y])) {
                        newState.addKey(grid[newState.x][newState.y]);
                    }

                    if (!isVisited.count(newState)) {
                        q.push(newState);
                        isVisited.insert(newState);
                    }
                }
            }
        }

        return -1;
    }

    pair<State, uint8_t> getInitState(const vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        uint8_t selfLocX = 0, selfLocY = 0;
        uint8_t keys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isSelf(grid[i][j])) {
                    selfLocX = i;
                    selfLocY = j;
                } else if (isKey(grid[i][j])) {
                    keys |= encodeKey(grid[i][j]);
                }
            }
        }

        return {{selfLocX, selfLocY, 0}, keys};
    }
};

int main(int argc, char** argv) {
//    Solution s;
//    vector<string> grid = {"@.a..","###.#","b.A.B"};
//    cout << s.shortestPathAllKeys(grid) << endl;
//    return 0;

    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t prevPos = 0;
    size_t currPos = 0;
    vector<string> result;
    std::string token;
    while (true) {
        currPos = s.find(delimiter, prevPos);
        token = s.substr(prevPos, currPos - prevPos);
        result.push_back(token);

        if (currPos == string::npos) {
            break;
        }

        currPos += delimiter.size();
        prevPos = currPos;
    }
}