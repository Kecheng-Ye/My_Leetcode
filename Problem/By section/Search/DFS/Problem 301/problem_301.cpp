#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(2^(l + r)), Space: O((l + r) * n)
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        if(!n) return {""};
        
        int l = 0, r = 0;
        for(const auto& c : s) {
            l += (c == '(');
            if(l == 0) {
                r += (c == ')');
            }else {
                l -= (c == ')');
            }
        }
        
        if(l + r == n) return {""};
        
        vector<string> result;
        DFS(result, s, l, r, 0);
        return result;
    }
    
    bool valid_parentheses(string s) {
        int left = 0, right = 0;
        
        for(const auto& c : s) {
            if(c == '(') {
                left++;
            }else if(c == ')') {
                right++;
            }
            
            if(right > left) return false;
        }
        
        return left == right;
    }
    
    void DFS(vector<string>& result, string& s, int l, int r, int idx) {
        if(l == 0 && r == 0 && valid_parentheses(s)) {
            string temp(s);
            result.push_back(temp);
        }else{
            for(int i = idx; i < s.size(); i++) {
                if(i > idx && s[i] == s[i - 1]) continue; // if we have consecutive same parenthesis, we only delete the first one
                
                string temp(s);
                if(r > 0 && s[i] == ')') {
                    temp.erase(i, 1);
                    DFS(result, temp, l, r - 1, i); // the reason why we pass i as the index is because we don't want to delete previous character in order to prevent duplicacy
                }else if(l > 0 && s[i] == '(') {
                    temp.erase(i, 1);
                    DFS(result, temp, l - 1, r, i);
                }
            }
        }
    }
};


int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}