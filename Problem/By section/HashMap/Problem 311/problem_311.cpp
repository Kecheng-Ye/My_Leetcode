#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(mnk) Space: O(m + n)
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        const int m = mat1.size(), k = mat1[0].size();
        const int n = mat2[0].size();

        vector<unordered_set<int>> rows(m), cols(n);

        // populate rows
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                if (mat1[i][j] != 0) {
                    rows[i].insert(j);
                }
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                if (mat2[i][j] != 0) {
                    cols[j].insert(i);
                }
            }
        }

        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cell = 0;
                
                for (const int nonZeroPos : rows[i]) {
                    if (cols[j].count(nonZeroPos)) {
                        cell += (mat1[i][nonZeroPos] * mat2[nonZeroPos][j]);
                    }
                }

                result[i][j] = cell;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}