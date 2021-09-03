#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count;
    
    // Time: O(n^2), Space: O(1)
    int countSubstrings(string s) {
        count = 0;
        
        // check all valid palindrome start from s[i]
        for(int i = 0; i < s.size(); i++) {
            extendSubstrings(s, i, i);
            extendSubstrings(s, i, i + 1);
        }
        
        return count;
    }
    
    void extendSubstrings(string& s, int start, int end) {
        while(start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
            count++;
        }
    
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}