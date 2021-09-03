#include <bits/stdc++.h>

using namespace std;

int count = 0;

void printIndent(int n) {
    for(int i = 0; i < n; i++) {
        printf("  ");
    }
}

class Solution {
public:
    const vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    // why this dynamic mark algorithm does not work
    // because if we search too deep on one direction and temporaily reach an end with no bound
    // we can not mark it because it may reach to another bound on another direction
    // void solve(vector<vector<char>>& board) {
    //     int m = board.size();
    //     if(!m) return;

    //     int n = board[0].size();
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));

    //     for(int i = 0; i < m; i++) {
    //         for(int j = 0; j < n; j++) {
    //             if(board[i][j] == 'O' && !visited[i][j]) {
    //                 // cout << "start dfs " << i << ' ' << j << endl;
    //                 // ::count = 0;
    //                 bool connect_to_board = false;
    //                 dfs(board, visited, i, j, m, n, connect_to_board);
    //             }
    //         }
    //     }

    // }

    // void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int m, int n, bool& current) {
    //     // printIndent(::count++);
    //     // cout << "start at " << x << ' ' << y << endl;

    //     if(x < 0 || y < 0 || x >= m || y >= n) {
    //         // printIndent(--(::count));
    //         // printf("Return at %d %d\n", x, y);
    //         return;
    //     }else if(visited[x][y] || board[x][y] == 'X') {
    //         // printIndent(--(::count));
    //         // printf("Return at %d %d with %s %s\n", x, y, 
    //         // visited[x][y] ? "true" : "false", board[x][y] == 'X' ? "true" : "false");
    //         return;
    //     }
    //     else{
    //         visited[x][y] = true;

    //         if(x == 0 || y == 0 || x == m - 1 || y == n - 1) {
    //             cout << "meet boundary" << endl;
    //             current = true;
    //         }

    //         for(auto& direction : directions) {
    //             dfs(board, visited, x + direction[0], y + direction[1], m, n, current);
    //         }

    //         // printIndent(::count);
    //         // cout << "mark " << x << " " << y << "as X" << endl;
    //         if(!current) board[x][y] ='X';
    //     }

    //     // printIndent(--(::count));
    //     // cout << "finsih at " << x << ' ' << y << endl;

    //     return;
    // }

    // Time: O(n), Space: O(1)
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m) return;

        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }

        for(int i = 0; i < n; i++) {
            dfs(board, 0, i, m, n);
            dfs(board, m - 1, i, m, n);
        }

        unordered_map<char, char> transform = {{'X', 'X'}, 
                                               {'*', 'O'},
                                               {'O', 'X'}};

        for(auto& i : board) {
            for(auto& j : i) {
                j = transform[j];
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O') return;

        board[x][y] = '*';

        for(auto& direction : directions) {
            dfs(board, x + direction[0], y + direction[1], m, n);
        }
    }

};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<char>> input = {{'O','X','O','O','X','X','X','O','O','O','O','O','X','O','O','O','O','X','O','X'},{'X','O','X','O','O','X','X','O','O','X','O','X','O','X','O','X','X','O','O','O'},{'O','X','O','O','O','X','X','X','X','O','O','O','O','O','X','X','X','X','O','X'},{'X','X','O','O','O','X','X','O','O','O','X','X','X','O','O','X','O','X','X','O'},{'O','X','O','X','X','O','X','O','O','O','X','O','O','X','O','O','O','O','O','X'},{'X','O','O','X','O','X','O','O','O','X','X','O','X','O','O','X','O','O','O','O'},{'X','O','O','O','X','X','O','O','O','O','O','X','O','O','X','O','O','O','O','X'},{'X','O','O','O','X','O','X','X','X','O','X','O','X','X','X','X','O','O','O','X'},{'X','O','O','X','O','O','O','X','O','O','O','O','O','O','O','O','O','X','O','X'},{'O','O','O','X','O','X','X','X','X','X','X','X','X','X','O','O','O','O','X','O'},{'X','O','X','O','X','O','O','X','X','X','O','X','X','O','O','X','X','O','O','O'},{'O','X','O','O','X','O','O','O','O','O','O','X','X','X','X','O','O','O','X','O'},{'X','O','O','O','X','X','X','O','X','O','O','O','X','O','X','O','X','O','O','X'},{'O','O','O','O','X','O','X','X','O','X','O','X','O','X','X','X','X','O','O','O'},{'O','X','X','O','O','O','O','X','O','O','X','X','X','O','O','X','X','O','X','O'},{'X','O','X','X','X','X','X','X','O','X','X','O','X','O','O','X','O','O','O','X'},{'X','O','O','O','X','O','X','O','O','X','O','X','O','O','X','O','O','X','X','X'},{'O','O','X','O','O','O','O','X','O','O','X','X','O','X','X','X','O','O','O','O'},{'O','O','X','O','O','O','O','O','O','X','X','O','X','O','X','O','O','O','X','X'},{'X','O','O','O','X','O','X','X','X','O','O','X','O','X','O','X','X','O','O','O'}};
    s.solve(input);
    return 0;
}

