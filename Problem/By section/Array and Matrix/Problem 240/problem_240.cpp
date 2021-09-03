#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(m + n), Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (target == matrix[row][col]) return true;
            else if (target < matrix[row][col]) col--;
            else row++;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}