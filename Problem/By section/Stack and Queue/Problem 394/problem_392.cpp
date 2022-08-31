#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Recursion Approach
    // n = length of final result string
    // k = number of "[]" pairs
    // Time: O(n), Space: O(k)
    // string decodeString(string s) {
    //     int n = s.size();
    //     int idx = 0;
    //     string result;

    //     return helper(s, idx);
    // }

    // string helper(string& s, int& idx) {
    //     int n = s.size();
    //     string result;

    //     int num = 0;
    //     while(idx < n) {
    //         if(isalpha(s[idx])) {
    //             int start = idx;
    //             while(idx < n && isalpha(s[idx]))
    //                 idx++;

    //             result += s.substr(start, idx - start);
    //         }else if(isdigit(s[idx])) {
    //             while(idx < n && isdigit(s[idx])) {
    //                 num = num * 10 + (s[idx++] - '0');
    //             }
    //         }else if(s[idx] == '[') {
    //             idx++;
    //             string sub = helper(s, idx);
    //             string temp;
    //             for(int i = 0; i < max(1, num); i++) {
    //                 temp += sub;
    //             }
    //             result += temp;
    //             num = 0;
    //         }else if(s[idx] == ']'){
    //             idx++;
    //             break;
    //         }
    //     }

    //     return result;
    // }

    // Stack Approach
    // n = length of final result string
    // m = length of input string
    // Time: O(n), Space: O(m)
    string decodeString(string s) {
        stack<string> st;
        string result;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                string temp;
                while (i < n && isalpha(s[i])) {
                    temp += s[i];
                    i++;
                }
                st.push(temp);
                i--;
            } else if (isdigit(s[i])) {
                string num;
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                st.push(num);
                i--;
            } else if (s[i] == '[') {
                st.push("[");
            } else {
                string sub;
                while (st.top() != "[") {
                    sub = st.top() + sub;
                    st.pop();
                }

                st.pop();
                string num = st.top();
                if (isdigit(num.back())) {
                    st.pop();
                } else {
                    num = "1";
                }

                string temp;
                for (int j = 0; j < stoi(num); j++) {
                    temp += sub;
                }
                st.push(temp);
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
