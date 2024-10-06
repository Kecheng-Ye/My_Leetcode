#include <bits/stdc++.h>

using namespace std;


// This is the GridMaster's API interface.
// You should not implement it, or speculate about its implementation
class GridMaster {
  public:
    bool canMove(char direction);
    void move(char direction);
    bool isTarget();
};


#define BLOCKED -1
#define EMPTY 1
#define START 3
#define END 2
#define VISITED 4

class Solution {
private:
    unordered_map<char, pair<int, int>> directions = {
        {'U', {-1, 0}},
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}}
    };

    unordered_map<char, char> opposite = {
        {'U', 'D'},
        {'D', 'U'},
        {'L', 'R'},
        {'R', 'L'}
    };

public:
    int findShortestPath(GridMaster &master) {
        const int xLimit = 1001, yLimit = 1001;

        vector<vector<int>> grid(xLimit, vector<int>(yLimit, BLOCKED));

        DFS(master, grid, xLimit / 2, yLimit / 2);
        grid[xLimit / 2][yLimit / 2] = START;

        queue<pair<int, int>> q;
        
        q.push({xLimit / 2, yLimit / 2});
        int step = 0;

        while (!q.empty()) {
            int currLvl = q.size();
            step++;

            while (currLvl--) {
                const auto [x, y] = q.front(); q.pop();

                for (const auto& [_, offset] : directions) {
                    const auto& [xDiff, yDiff] = offset;
                    const int newX = x + xDiff, newY = y + yDiff;
                    
                    if (grid[newX][newY] == BLOCKED || grid[newX][newY] == VISITED) {
                        continue;
                    }

                    if (grid[newX][newY] == END) return step;

                    grid[newX][newY] = VISITED;
                    q.push({newX, newY});
                }
            }
        }

        return -1;

    }

    void DFS(GridMaster &master, vector<vector<int>> &grid, const int x, const int y) {
        if (master.isTarget()) {
            grid[x][y] = END;
        } else {
            grid[x][y] = EMPTY;
        }

        for (const auto& [dir, offset] : directions) {
            const auto& [xDiff, yDiff] = offset;
            const int newX = x + xDiff, newY = y + yDiff;

            if (!master.canMove(dir)) {
                continue;
            }

            if (grid[newX][newY] == BLOCKED) {
                master.move(dir);

                DFS(master, grid, newX, newY);

                master.move(opposite[dir]);
            }
        }

        return;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}