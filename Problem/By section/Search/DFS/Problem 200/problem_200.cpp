#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    
    // Time: O(n), Space: O(1)
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    answer++;
                    explore(grid, i, j);
                }
            }
        }

        return answer;
    }


    void explore(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j > grid[0].size() || grid[i][j] != '1') return;

        // 2 stands for explored island that no longer need to be traversed again
        grid[i][j] = '2';

        for(auto direction : directions) {
            explore(grid, i + direction[0], j + direction[1]);
        }

    }
};

int main(int argc, char** argv) {
    return 0;
}