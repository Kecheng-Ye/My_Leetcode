#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n^n), Space: O(n)
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return vector<vector<string>>();

        vector<vector<int>> result;
        vector<int> single_result;
        vector<bool> vertical(n, false);
        vector<bool> upper_left_diagonal(2 * n - 1, false);
        vector<bool> lower_right_diagonal(2 * n - 1, false);

        backtrack(result, single_result, vertical, upper_left_diagonal, lower_right_diagonal, 0, n);

        vector<vector<string>> final_result;
        decode_queen_repr(result, final_result, n);

        return final_result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& single_result, vector<bool>& vertical, vector<bool>& upper_left_diagonal, vector<bool>& lower_right_diagonal, int i, int n) {
        if(i == n) {
            result.push_back(single_result);
        }else{
            for(int j = 0; j < n; j++) {
                int upper_left_diagonal_idx = upper_left_diagonal_encode(n, i, j);
                int lower_right_diagonal_idx = lower_right_diagonal_encode(n, i, j);
                if(vertical[j] || upper_left_diagonal[upper_left_diagonal_idx] || lower_right_diagonal[lower_right_diagonal_idx]) continue;

                single_result.push_back(j);
                vertical[j] = true;
                upper_left_diagonal[upper_left_diagonal_idx] = true;
                lower_right_diagonal[lower_right_diagonal_idx] = true;

                backtrack(result, single_result, vertical, upper_left_diagonal, lower_right_diagonal, i + 1, n);

                single_result.pop_back();
                vertical[j] = false;
                upper_left_diagonal[upper_left_diagonal_idx] = false;
                lower_right_diagonal[lower_right_diagonal_idx] = false;
            }
        }
    }

    int upper_left_diagonal_encode(int size, int i, int j) {
        int row = i, col = j;

        while(true) {
            if(row - 1 < 0 || col + 1 >= size) break;

            row--;
            col++;
        }

        int result = (row == 0) ? col : (size - 1 + row);

        return result;
    }

    int lower_right_diagonal_encode(int size, int i, int j) {
        int row = i, col = j;

        while(true) {
            if(row - 1 < 0 || col - 1 < 0) break;

            row--;
            col--;
        }

        int result = (col == 0) ? ( size - 1 - row) : (size - 1 + col);

        return result;
    }

    void decode_queen_repr(vector<vector<int>>& encode, vector<vector<string>>& result, int n) {
        for(auto& each_ans : encode) {
            vector<string> temp(n, string(n, '.'));
            int count = 0;
            for(auto& i : each_ans) {
                temp[count][i] = 'Q';
                count++;
            }
            result.push_back(temp);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}