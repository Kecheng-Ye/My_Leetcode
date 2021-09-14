#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}