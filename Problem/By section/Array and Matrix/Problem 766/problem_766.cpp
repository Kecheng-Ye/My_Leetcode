#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            if(!traverse_diagnol(matrix, i, 0, m, n, matrix[i][0])) return false;
        }
        
        for(int i = 1; i < n; i++) {
            if(!traverse_diagnol(matrix, 0, i, m, n, matrix[0][i])) return false;
        }
        
        return true;
    }
    
    bool traverse_diagnol(vector<vector<int>>& matrix, int i, int j, int m, int n, int target) {
        for(int row = i, col = j; row < m && col < n; row++, col++) {
            if(matrix[row][col] != target) return false;
        }
        
        return true;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}