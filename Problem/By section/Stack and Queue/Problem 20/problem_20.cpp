#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<char> left_bracket = {'(', '{', '['};
    unordered_set<char> right_bracket = {')', '}', ']'};
    
    unordered_map<char, char> right2left = {{')', '('},
                                            {'}', '{'},
                                            {']', '['}};
    
    // Time: O(n), Space: O(n)
    bool isValid(string s) {
        int size = s.size();
        if(size % 2 != 0) return false;
        
        stack<char> k;
        int cnt = 1;
        k.push(s[0]);
        
        while(cnt < size) {
            char new_bracket = s[cnt++];
            if(left_bracket.count(new_bracket)) {
                k.push(new_bracket);
            }else{               
                if(k.empty() || right2left[new_bracket] != k.top()) return false;
                
                k.pop();
            }
        }
        
        return k.empty();
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}