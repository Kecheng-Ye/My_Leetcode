#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp[i] = the Decode Ways for the substring of s[0, i]
    // update rule
    // dp = dp[i - 1] + dp[i - 2] (if the substring of(i - 2, i) is <= 26 && > 0)

    // Time: O(n), Space: O(1)
    int numDecodings(string s) {
        int size = s.length();
        if(size == 0 || s[0] == '0') return 0;

        // only dp[i - 1] and dp[i - 2] is involved
        // so we can optimize it
        int prev_1 = 1;
        int prev_2 = 1;

        for(int i = 1; i < size; i++) {
            int result = 0;
            if(s[i] != '0') {
                result += prev_1;
            }

            if(s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) {
                result += prev_2;
            }

            prev_2 = prev_1;
            prev_1 = result;
        }

        return prev_1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << stoi("a") << endl;
    return 0;
}