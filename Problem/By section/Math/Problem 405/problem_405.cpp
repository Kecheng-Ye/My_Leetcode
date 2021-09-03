#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(!num) return "0";
        
        int mask = 0xf;
        string result = "";
        unsigned int temp = num;
        while(temp != 0) {
            result = toSigleHex(temp & mask) + result;
            temp >>= 4;
        }
        
        return result;
    }
    
    char toSigleHex(int num) {
        if(num < 10) {
            return (char)('0' + num);
        }else{
            return (char)('a' + num - 10);
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.toHex(-1) << endl;
    // int a = 0xffffffff;
    // cout << hex << (a >> 4) << endl;
    return 0;
}