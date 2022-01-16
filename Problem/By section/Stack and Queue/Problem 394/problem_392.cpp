#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int idx = 0;
        string result;
        
        while(idx < n) {
            result += helper(s, idx);
        }
        return result;
        
    }
    
    string helper(string& s, int& idx) {
        int n = s.size();
        string result;
        stack<string> st;
        
        int num = 0;
        while(idx < n) {
            if(isalpha(s[idx])) {
                int start = idx;
                while(idx < n && isalpha(s[idx]))
                    idx++;

                st.push(s.substr(start, idx - start));
                
            }else if(isdigit(s[idx])) {
                while(idx < n && isdigit(s[idx])) {
                    num = num * 10 + (s[idx++] - '0');
                }
            }else if(s[idx] == '[') {
                idx++;
                string sub = helper(s, idx);
                string temp;
                for(int i = 0; i < max(1, num); i++) {
                    temp += sub;   
                }
                st.push(temp);
                num = 0;
            }else if(s[idx] == ']'){
                idx++;
                break;
            }
        }
        
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}