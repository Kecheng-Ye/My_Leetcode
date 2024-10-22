#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        bool needCrush = true;
        
        while (needCrush) {
            needCrush = discover(board, m, n);
            
            if (needCrush) {
                crush(board);
            }
        }
        
        return board;
    }
    
    int discover(vector<vector<int>>& board, const int m, const int n) {
        bool needCrush = false;

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 0) {
                    continue;
                }

                const int currValue = abs(board[i][j]);
                if (currValue == abs(board[i][j - 1]) && currValue == abs(board[i][j + 1])) {
                    needCrush = true;
                    board[i][j] = -1 * currValue;
                    board[i][j - 1] = -1 * currValue;
                    board[i][j + 1] = -1 * currValue;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[j][i] == 0) {
                    continue;
                }

                const int currValue = abs(board[j][i]);
                if (currValue == abs(board[j - 1][i]) && currValue == abs(board[j + 1][i])) {
                    needCrush = true;
                    board[j][i] = -1 * currValue;
                    board[j - 1][i] = -1 * currValue;
                    board[j + 1][i] = -1 * currValue;
                }
            }
        }

        if (needCrush) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] < 0) {
                        board[i][j] = 0;
                    }
                }
            }
        }

        return needCrush;
    }
    
    void crush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int j = 0; j < n; j++) {
            int firstZero = -1;
            for (int i = m - 1; i >= 0; i--) {
                if (board[i][j] == 0) {
                    firstZero = max(firstZero, i);
                } else if (firstZero >= 0) {
                    swap(board[i][j], board[firstZero--][j]);
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}