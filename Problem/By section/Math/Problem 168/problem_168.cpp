#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result  = "";
        
        while(columnNumber) {
            char add_letter = (--columnNumber) % 26 + 'A';
            columnNumber /= 26;
            result = add_letter + result;
        }
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}