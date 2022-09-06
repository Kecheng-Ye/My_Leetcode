#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    int countBinarySubstrings(string s) {
        int n = s.size();
        if(n <= 1) return 0;

        int prev = 0, cur = 1;
        int result = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] != s[i - 1]) {
                result += min(prev, cur);
                prev = cur;
                cur = 1;
            }else{
                cur += 1;
            }
        }

        return result + min(prev, cur);
    }
};

int main(int argc, char** argv) {
    Solution s;

    return 0;
}
