#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
public:
    TicTacToe(int n): _n(n), rows(n), cols(n), leftDiagonal(0), rightDiagonal(0) {
        
    }
    
    // Time: O(1), Space: O(1)
    int move(int row, int col, int player) {
        int playId = (player == 1) ? 1 : -1;

        rows[row] += playId;
        cols[col] += playId;

        if (row == col) {
            leftDiagonal += playId;
        }

        if (row + col == (_n - 1)) {
            rightDiagonal += playId;
        }

        return (
            abs(rows[row]) == _n ||
            abs(cols[col]) == _n ||
            abs(leftDiagonal) == _n ||
            abs(rightDiagonal) == _n
        ) ? player : 0;
    }

    const int _n;
    vector<int> rows;
    vector<int> cols;
    int leftDiagonal;
    int rightDiagonal;
};


int main(int argc, char** argv) {
    return 0;
}