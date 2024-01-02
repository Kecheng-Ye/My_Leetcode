#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // dp[i][j] = the minimal editing different from word1[0,i] to word2[0,j]
    // update rule
    // if you get a character match in word1[i] and word2[j]
    // dp[i][j] = dp[i - 1][j - 1]
    // else you have to consider three operation
    // 1. insert, 2. delete, 3. replace
    // dp[i][j] = min( dp[i - 1][j - 1]             if we choose to replace
    //                 dp[i - 1][j]                 if we choose to delete
    //                 dp[i][j - 1])                if we choose to insert
    // vector<vector<int>> dp;

    // int minDistance(string word1, string word2) {
    //     int size_1 = word1.size(), size_2 = word2.size();
    //     if(size_1 == 0) return size_2;
    //     if(size_2 == 0) return size_1;

    //     dp = vector<vector<int>>(size_1 + 1, vector<int>(size_2 + 1, 0));

    //     for(int i = 1; i <= size_2; i++) {
    //         dp[0][i] = i;
    //     }

    //     for(int i = 1; i <= size_1; i++) {
    //         dp[i][0] = i;
    //     }

    //     for(int i = 1; i <= size_1; i++) {
    //         for(int j = 1; j <= size_2; j++) {
    //             dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);

    //             if(word1[i - 1] == word2[j - 1]){
    //                 dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
    //             }else{
    //                 dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
    //             }
    //         }
    //     }

    //     return dp[size_1][size_2];
    // }

    vector<int> dp;

    int minDistance(string word1, string word2) {
        int size_1 = word1.size(), size_2 = word2.size();
        if(size_1 == 0) return size_2;
        if(size_2 == 0) return size_1;

        dp = vector<int>(size_1 + 1);

        for(int i = 1; i <= size_1; i++) {
            dp[i] = i;
        }

        int up_left = INT_MAX;

        for(int j = 1; j <= size_2; j++) {
            for(int i = 0; i <= size_1; i++) {
                if (i == 0) {
                    up_left = dp[0];
                    dp[0] = j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    int temp = dp[i];
                    dp[i] = up_left;
                    up_left = temp;
                } else {
                    int up = dp[i];
                    int left = dp[i - 1];

                    dp[i] = min(up, min(left, up_left)) + 1;
                    up_left = up;
                }
            }
        }

        return dp[size_1];
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
