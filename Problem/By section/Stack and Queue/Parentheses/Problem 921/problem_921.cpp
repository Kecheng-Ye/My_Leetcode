#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        int open = 0;
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            }else if(s[i] == ')') {
                if(open > 0) {
                    open--;
                }else{
                    result++;
                }
            }
        }
        
        result += open;
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}