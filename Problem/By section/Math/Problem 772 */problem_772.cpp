#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string& s) {
        int start = 0;
        return calculate_helper(s, start);
    }
    
    int calculate_helper(string& s, int& start) {
        int n = s.size();
        
        if(start >= n) {
            return 0;    
        }
        
        char sign = '+';
        int num = 0;
        stack<int> st;
        
        while(start < n) {
            if(isdigit(s[start])) {
                num = num * 10 + (s[start] - '0');
            }
            
            if(!isdigit(s[start]) || start == n - 1){
                if(s[start] == '(') {
                    num = calculate_helper(s, ++start);
                }
                
                if(s[start] != ' ' || start >= n - 1 || s[start] == ')'){
                    int prev;
                    // calcuate the num result for previous sign
                    switch(sign) {
                        case '+':
                            st.push(num);
                            break;
                        case '-':
                            st.push(-num);
                            break;
                        case '*':
                            prev = st.top();
                            st.pop();
                            st.push(prev * num);
                            break;
                        case '/':
                            prev = st.top();
                            st.pop();
                            st.push(prev / num);
                            break;
                    }
                    
                    // then cache the current sign
                    sign = s[start];
                    
                    // if this char is a back bracket
                    // we should exit the loop immediately
                    if(s[start] == ')') {
                        start++;
                        break;
                    }
                    
                    // fresh the num
                    num = 0;
                }
            }
            
            start++;
        }
        
        int result = 0;
        
        // empty the stack for calculation
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}