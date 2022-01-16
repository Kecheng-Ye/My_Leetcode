#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(n), Space: O(n)
    string removeDuplicates(string str) {
        stack<char> s;
        
        for(const char c : str) {
            if(s.empty()) {
                s.push(c);
            }else{
                char prev = s.top();
                
                if(prev == c) {
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }
        
        string result;
        while(!s.empty()) {
            result += s.top();
            s.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}