#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // vector<int> countBits(int n) {
    //     if(n == 0) return {0};
    //     if(n == 1) return {0, 1};
    //     vector<int> result(n + 1, 0);
    //     result[0] = 0;
    //     result[1] = 1;
    //     int cur_len = 2;
        
    //     for(int i = 2; i < n + 1; i++) {
    //         for(int j = 0; j < cur_len && i + j < n + 1; j++) {
    //             result[i + j] = 1 + result[j];
    //         }
    //         i += cur_len - 1;
    //         cur_len *= 2;
    //     }
        
    //     return result;
    // }

    // For 6(110) = 4(100) + 2(10)
    // dp[i] = 1 + dp[i & (i - 1)]
    // Time: O(n), Space: O(1)
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for(int i = 1; i <= n; i++){
            result[i] = result[i&(i-1)] + 1;
        }
    return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}