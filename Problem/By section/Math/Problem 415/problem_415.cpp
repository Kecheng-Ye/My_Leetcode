#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        int digit_1, digit_2;
        string result = "";
        
        while(i >= 0 || j >= 0 || carry != 0) {
            digit_1 = (i >= 0) ? (num1[i--] - '0') : 0;
            digit_2 = (j >= 0) ? (num2[j--] - '0') : 0;
            carry += digit_1 + digit_2;
            result = (char)((carry % 10) + '0') + result;
            carry /= 10;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}