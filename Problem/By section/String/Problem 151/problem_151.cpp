#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(1)
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        const int n = s.size();
        int i = 0, left = 0, right = 0;

        while (true) {
            // skip space
            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i == n) break;

            // find word
            while (i < n && s[i] != ' ') {
                // move all the string to replace any space
                s[right++] = s[i++];
            }

            // currently right is point to a space
            reverse(s.begin() + left, s.begin() + right);

            s[right++] = ' ';
            left = right;
        }

        s.resize(right - 1);
        return s;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}