#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space:O(1)
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        if(!m) return mat;
        int n = mat[0].size();
        if(r * c != m * n) return mat;
        
        vector<vector<int>> result(r, vector<int>(c, 0));
        
        int idx = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                result[i][j] = mat[idx / n][idx % n];
                idx++;
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}