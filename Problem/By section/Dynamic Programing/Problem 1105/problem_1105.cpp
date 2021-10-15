#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = minimum height of placing books[0 : i] into the shelf
    // Update Rule
    // dp[i] = argmin_j(dp[j] + max(books.height[j : i])) where sum(books.width[j : i]) < shelfWidth
    // Time: O(n^2), Space: O(n)
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if(n == 1) return books[0][1];
        
        vector<int> dp(n, INT_MAX);
        dp[0] = books[0][1];
        
        for(int i = 1; i < n; i++) {
            int sum_w = 0;
            int max_h = INT_MIN;
            
            for(int j = i; j >= 0; j--) {
                if(sum_w + books[j][0] > shelfWidth) break;
                max_h = max(books[j][1], max_h);
                sum_w += books[j][0];
                
                dp[i] = min(dp[i], ((j == 0) ? 0 : dp[j - 1]) + max_h);
            }
        }
        
        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}