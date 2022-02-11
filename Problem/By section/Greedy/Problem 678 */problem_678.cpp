#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // max_open = max number of left parentheses this string can generate
    // min_open = min number of left parentheses this string can generate
    // Time: O(n), Space: O(1)
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                min_open += 1;
                max_open += 1;
            }else if(s[i] == ')') {
                min_open -= 1;
                max_open -= 1;
            }else{
                min_open -= 1;
                max_open += 1;
            }
            
            min_open = max(0, min_open);
            if(max_open < 0) return false;
        }
        
        return min_open == 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}