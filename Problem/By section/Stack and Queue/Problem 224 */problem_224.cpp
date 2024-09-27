#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const unordered_set<char> signs = {
        '+', '-', '*', '/'
    };

    // Time: O(n), Space: O(n)
    int calculate(string s) {
        int idx = 0;
        return calculateHelper(s, idx);
    }

    int calculateHelper(const string& c, int& i) {
        stack<int> st;
        char sign = '+';
        int num = 0;

        const auto numCalc = [&]() {
            switch (sign) {
                case '+': {
                    st.push(num);
                    break;
                }

                case '-' : {
                    st.push(-1 * num);
                    break;
                }

                case '*': {
                    const int prev = st.top(); st.pop();
                    st.push(prev * num);
                    break;
                }

                case '/': {
                    const int prev = st.top(); st.pop();
                    st.push(prev / num);
                    break;
                }
            }
        };

        while (i < c.size()) {
            if (c[i] == ' ') {
                i++;
            } else if (isdigit(c[i])) {
                num = readNum(c, i);
            } else if (c[i] == '(') {
                i++;
                num = calculateHelper(c, i);
                assert(c[i] == ')');
                i++;
            } else if (c[i] == ')') {
                break;
            } else {
                assert(signs.count(c[i]));

                numCalc();

                num = 0;
                sign = c[i++];
            }
        }

        numCalc();

        int result = 0;
        while (!st.empty()) {
            int num = st.top(); st.pop();
            result += num;
        }

        return result;
    }

    int readNum(const string& c, int& i) {
        int num = 0;
        while ((i < c.size()) && isdigit(c[i])) {
            num = num * 10 + (c[i++] - '0');
        }

        return num;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}