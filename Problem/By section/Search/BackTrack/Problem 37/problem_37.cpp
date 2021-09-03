#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(!board.size()) return;

        vector<vector<int>> vertical(9, vector<int>(9, 0));
        vector<vector<int>> horizontal(9, vector<int>(9, 0));
        vector<vector<int>> blocks(9, vector<int>(9, 0));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                
                int idx = board[i][j] - '1';
                vertical[j][idx] = 1;
                horizontal[i][idx] = 1;
                blocks[idx_2_block(i, j)][idx] = 1;
            }
        }

        backtrack(board, vertical, horizontal, blocks, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, vector<vector<int>>& vertical, vector<vector<int>>& horizontal, vector<vector<int>>& blocks, int i, int j){
        if(i == board.size()) {
            return true;
        }else{
            int next_i = (j + 1 == board[0].size()) ? i + 1 : i;
            int next_j = (j + 1 == board[0].size()) ? 0 : j + 1;
            
            
            if(board[i][j] != '.') return backtrack(board, vertical, horizontal, blocks, next_i, next_j);

            for(int k = 0; k < 9; k++) {
                if(horizontal[i][k] != 0 || vertical[j][k] != 0 || blocks[idx_2_block(i, j)][k] != 0) continue;

                board[i][j] = '1' + k;
                vertical[j][k] += 1;
                horizontal[i][k] += 1;
                blocks[idx_2_block(i, j)][k] += 1;

                if(backtrack(board, vertical, horizontal, blocks, next_i, next_j)) return true;

                board[i][j] = '.';
                vertical[j][k] -= 1;
                horizontal[i][k] -= 1;
                blocks[idx_2_block(i, j)][k] -= 1;
            }

            return false;
        }
    }

    int idx_2_block(int i, int j) {
        return (i/3 * 3 + j/3);
    }
};

int main(int argc, char** argv) {
    Solution s;
    int i = 5;
    int j = 8;
    cout << (char)('0' + 9) << endl;
    return 0;
}