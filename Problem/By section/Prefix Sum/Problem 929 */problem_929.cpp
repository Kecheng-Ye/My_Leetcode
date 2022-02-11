#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // we want left x zeros and right N-x ones
    // so we have to flip all the 1 in the [0 : x] part and all the 0 in [x :] part
    // Time: O(n), Space: O(n)
    int minFlipsMonoIncr(string S) {
        int N = S.length();
        vector<int> P(N + 1);
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (S[i] == '1' ? 1 : 0);

        int ans = INT_MAX;
        for (int j = 0; j <= N; ++j) {
            ans = min(ans, P[j] + N-j-(P[N]-P[j]));
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}