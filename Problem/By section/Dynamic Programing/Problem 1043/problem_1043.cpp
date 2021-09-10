#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = max sum can be achieved for arr[1 : i] with subarray which length is at most k
    // dp[i] = argmax_k(dp[k] + (i - k + 1) * max(arr[k : i]))
    // Time: O(n^2), Space: O(n)
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> dp(n, 0);
        int _max = arr[0];
        for(int i = 0; i < k; i++) {
            _max = max(_max, arr[i]);
            dp[i] = (i + 1) * _max;
        }
        
        for(int i = k; i < n; i++) {
            _max = arr[i];
            int ptr = i;
            while(i - ptr < k) {
                _max = max(_max, arr[ptr]);
                dp[i] = max(dp[i], dp[ptr - 1] + _max * (i - ptr + 1));
                ptr--;
            }
        }
        
        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}