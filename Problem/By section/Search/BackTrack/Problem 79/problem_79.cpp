#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    // Time: O(4^n), Space: O(n)
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(!m) return false;

        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word[0] == board[i][j]) {
                    if(backtrack(board, word, visited, 0, i, j, m, n)) return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int idx, int x, int y, int m, int n) {
        if(idx == word.length()) {
            return true;
        }else if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[idx] || visited[x][y]) {
            return false;
        }else{
            visited[x][y] = true;

            for(auto& direction : directions) {
                if(backtrack(board, word, visited, idx + 1, x + direction[0], y + direction[1], m, n)) return true;
                
            }

            visited[x][y] = false;

            return false;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<char>> input = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << s.exist(input, word) << endl;
    return 0;
}