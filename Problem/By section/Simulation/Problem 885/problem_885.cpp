#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(max(max(rStart, rows - rStart), max(cols, cols - cStart)) ^ 2), Space: O(1)
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result = {{rStart, cStart}};
        int limit = rows * cols - 1;

        const auto isValid = [&](const int x, const int y) -> bool {
            return x >= 0 && x < rows && y >= 0 && y < cols;
        };

        const function<void(const int)> traverse = [&](const int radius) -> void {
            if (limit == 0) return;

            const int xMin =  rStart - radius, xMax = rStart + radius;
            const int yMin =  cStart - radius, yMax = cStart + radius;
            int i = xMin + 1, j = yMax;

            while (i <= xMax) {
                if (isValid(i, j)) {
                    result.push_back({i, j});
                    limit--;
                }
                i++;
            }
            
            i = xMax, j = yMax - 1;
            while (j >= yMin) {
                if (isValid(i, j)) {
                    result.push_back({i, j});
                    limit--;
                }
                j--;
            }

            i = xMax - 1, j = yMin;
            while (i >= xMin) {
                if (isValid(i, j)) {
                    result.push_back({i, j});
                    limit--;
                }
                i--;
            }
            
            i = xMin, j = yMin + 1;
            while (j <= yMax) {
                if (isValid(i, j)) {
                    result.push_back({i, j});
                    limit--;
                }
                j++;
            }
            traverse(radius + 1);
        };

        traverse(1);
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}