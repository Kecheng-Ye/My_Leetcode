#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(m * n * min(m, n)), Space: O(1)
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int result = 0;
        
        
    //     for(int i = 0; i < m; i++) {
    //        for(int j = 0; j < n; j++) {
    //            if(matrix[i][j] == '1') {
    //                result = max(result, expand(matrix, i, j, m, n));
    //            }
    //        } 
    //     }
        
    //     return result * result;
    // }
    
    // int expand(vector<vector<char>>& matrix, int i, int j, int m, int n) {
    //     int result = 1;
    //     pair<int, int> up_right(i, j);
    //     pair<int, int> bottom_left(i, j);
        
    //     bool extend = true;
    //     while(up_right.second + 1 < n && bottom_left.first + 1 < m && extend) {
    //         for(int i = up_right.first; i <= up_right.first + result; i++) {
    //             if(matrix[i][up_right.second + 1] != '1') {
    //                 extend = false;
    //                 break;
    //             }
    //         }
            
    //         if(!extend) break;
            
    //         for(int i = bottom_left.second; i <= bottom_left.second + result - 1; i++) {
    //             if(matrix[bottom_left.first + 1][i] != '1') {
    //                 extend = false;
    //                 break;
    //             }
    //         }
            
    //         if(extend) {
    //             result++;
    //             up_right.second++;
    //             bottom_left.first++;
    //         }
    //     }
        
    //     return result;
    // }
    
    // dp[i][j] = the maxmial length of all 1 square which its right bottom corner is matrix[i][j]
    // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1
    // Time: O(m * n), Space: O(m * n)
    // int maximalSquare(vector<vector<char>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int result = 0;
    //     vector<vector<int>> dp(m, vector<int>(n));
        
    //     for(int i = 0; i < m; i++) {
    //        for(int j = 0; j < n; j++) {
    //            if(matrix[i][j] == '1') {
    //                int left_up = 0, left = 0, up = 0;
    //                if(j - 1 >= 0) {
    //                    left = dp[i][j - 1];
    //                }
                   
    //                if(i - 1 >= 0) {
    //                    up = dp[i - 1][j];
    //                }
                   
    //                if(j - 1 >= 0 && i - 1 >= 0) {
    //                    left_up = dp[i - 1][j - 1];
    //                }
                   
    //                dp[i][j] = min(left, up);
    //                dp[i][j] = min(dp[i][j], left_up);
    //                dp[i][j]++;
                   
                   
    //                result = max(dp[i][j], result);
    //            }
    //        } 
    //     }
        
    //     return result * result;
    // }
    
    // Can be optimized because dp[i][j] only relates with dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]
    // left prev = dp[i - 1][j - 1], we can compress the 2d dp into 1d
    // Time: O(m * n), Space: O(n)
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        int prev = 0;
        vector<int> dp(n + 1);
        
        for(int i = 1; i <= m; i++) {
           for(int j = 1; j <= n; j++) {
               int temp = dp[j];
               if(matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], dp[j]), prev) + 1;
                    result = max(dp[j], result);
               }else{
                   dp[j] = 0; // very important, need to fresh, or it will inheritit the dp[i - 1][j]'s value
               }
               prev = temp;
           } 
        }
        
        return result * result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}