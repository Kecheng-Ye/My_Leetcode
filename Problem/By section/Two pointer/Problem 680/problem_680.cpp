#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left <= right) {
            if(s[left] != s[right]) {
                return (validPalindrome_helper(s, left + 1, right) || validPalindrome_helper(s, left, right - 1));
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome_helper(string &s, int left, int right) {
        while(left <= right) {
            // inplace ++ and -- into the if condition 
            // will significantly boost performance
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

void foo(int i) {
    i ++;
}

int main(int argc, char** argv) {
    Solution solution;
    std::cout << solution.validPalindrome("abaa") << std::endl;
    return 0;
}