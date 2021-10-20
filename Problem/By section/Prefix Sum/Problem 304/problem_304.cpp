#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    // prefix_sum[i][j] = sum value from matrix[0 : i][0 : j]
    // Update Rule:
    // prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i][j]
    // Time: O(mn), Space: O(mn)
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_sum = vector<vector<int>>(m, vector<int>(n, 0));
        prefix_sum[0][0] = matrix[0][0];
        
        for(int i = 1; i < m; i++) {
            prefix_sum[i][0] += prefix_sum[i - 1][0] + matrix[i][0];
        }
        
        for(int i = 1; i < n; i++) {
            prefix_sum[0][i] += prefix_sum[0][i - 1] + matrix[0][i];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i][j];
            }
        }
        
    }
    
    // Time: O(1), Space: O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = (row1 > 0) ? prefix_sum[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? prefix_sum[row2][col1 - 1] : 0;
        int up_left = (row1 > 0 && col1 > 0) ? prefix_sum[row1 - 1][col1 - 1] : 0;
        
        return prefix_sum[row2][col2] - up - left + up_left;
    }
    
private:
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}