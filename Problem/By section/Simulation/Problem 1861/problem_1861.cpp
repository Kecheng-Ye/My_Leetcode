#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(mn), Space: O(1)
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> dp(n, vector<char>(m, '.'));
        
        for(int i = m - 1; i >= 0; i--) {
            int next_free = n - 1; // the next aviliable point for potential stone
            for(int j = n - 1; j >= 0; j--) {
                int ori_m = m - 1 - i;
                int ori_n = j;
                
                if(box[ori_m][ori_n] == '*') {
                    dp[j][i] = '*';
                    next_free = j - 1; // should above the obstacle
                }else if(box[ori_m][ori_n] == '.') {
                    next_free = max(next_free, j); // should consider the lowest empty spot first
                }
                else if(box[ori_m][ori_n] == '#'){
                    dp[next_free][i] = box[ori_m][ori_n];
                    next_free--; // after we fill an empty spot with a stone, we should decrement the empty spot
                }
            }
        }
        
        return dp;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    int a, b, c;
    a = b = c = 1;

    return 0;
}