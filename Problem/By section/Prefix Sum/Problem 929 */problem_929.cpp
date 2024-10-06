#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // we want left x zeros and right N-x ones
    // so we have to flip all the 1 in the [0 : x] part and all the 0 in [x :] part
    // Time: O(n), Space: O(n)
    int minFlipsMonoIncr(string s) {
        const int n = s.size();
        if (n == 1) return 0;

        vector<int> zeros(n + 1);

        for (int i = 0; i < n; i++) {
            zeros[i + 1] = (s[i] == '0') + zeros[i];
        }

        int result = INT_MAX;
        for (int i = 0; i <= n; i++) {
            // make s[:i] to be zero
            const int leftOnes = i - zeros[i];
            // make s[i:] to be one
            const int rightZeros = (zeros[n] - zeros[i]);

            result = min(result, leftOnes + rightZeros);
        }

        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}