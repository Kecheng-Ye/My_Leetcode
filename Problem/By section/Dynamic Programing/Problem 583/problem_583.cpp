#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    int minDistance(string word1, string word2) {
        int size_1 = word1.size();
        int size_2 = word2.size();
        
        if(size_1 == 0) return size_2;
        if(size_2 == 0) return size_1;
        
        dp = vector<vector<int>>(size_1 + 1, vector<int>(size_2 + 1, 0));
        for(int i = 0; i < size_1; i++) {
           for(int j = 0; j < size_2; j++) {
               if(word1[i] == word2[j]) {
                   dp[i + 1][j + 1] = 1 + dp[i][j];
               }else{
                   dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
               }
           } 
        }
        
        return (size_1 + size_2 - 2 * dp[size_1][size_2]);
        
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}