#include <bits/stdc++.h>

using namespace std;


// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
    int get(int row, int col);
    vector<int> dimensions();
};


class Solution {
public:
    // Time: O(n + m) Space: O(1)
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const vector<int> dim = binaryMatrix.dimensions();
        const int m = dim[0], n = dim[1];

        int i = m - 1, j = n - 1;
        int result = -1;

        while (i >= 0 && j >= 0) {
            if (binaryMatrix.get(i, j) == 1) {
                result = j--;
            } else {
                i--;
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}