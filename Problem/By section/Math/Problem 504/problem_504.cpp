#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        
        bool negative = (num < 0);
        string result = "";
        num = negative ? -num : num;
        while(num > 0){
            result = to_string(num % 7) + result;
            num /= 7;
        }
        
        result = negative ? "-" + result : result;
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    string test = "";
    test += '1';
    return 0;
}