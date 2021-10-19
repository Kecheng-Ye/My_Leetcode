#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(mn^2), Space: O(n^2)
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 1) return 0;
        
        int n = grid[0].size();
        int result = 0;
        unordered_map<int, int> record; // for recording the number of rectangles from previous row 
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int k = j + 1; k < n; k++) {
                        if(grid[i][k] == 1) {
                            int key = 200 * j + k; // hash key
                            int count = record[key]; // get the previous row sum
                            result += count; // update the final answer
                            record[key]++; // update hash table
                        }
                    }   
                }
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}