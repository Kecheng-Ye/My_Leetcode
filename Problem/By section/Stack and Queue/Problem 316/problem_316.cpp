#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // we maintain a last_occur arr to represent the last index that one particular char occur at the string
    // then use a stack to do the traverse
    // once we meet a char that is lexicolly smaller than the top element of the stack and also the top element is not the final occurance in the string
    // then we can remove it 
    // also we maintain a has_seen hashset to monitor the state of the stack
    // because we want the stack to contain each character only once

    // Time: O(n), Space: O(n)
    string removeDuplicateLetters(string s) {
        int n = s.size();
        
        vector<int> last_occur(26, -1);
        
        for(int i = 0; i < n; i++) {
            last_occur[s[i] - 'a'] = i;
        }
        
        stack<char> st;
        unordered_set<char> has_seen;
        
        st.push(s[0]);
        has_seen.insert(s[0]);
        for(int i = 1; i < n; i++) {
            char cur = s[i];
            if(has_seen.count(cur)) continue;
            
            while(!st.empty() && cur < st.top() && last_occur[st.top() - 'a'] > i) {
                has_seen.erase(st.top());
                st.pop();
            }
            
            st.push(cur);
            has_seen.insert(cur);
        }
        
        string result;
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}