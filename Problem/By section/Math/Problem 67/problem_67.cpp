#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int size_a = a.size();
        int size_b = b.size();
        string longer = (size_a >= size_b) ? a : b;
        string shorter = (size_a >= size_b) ? b : a;
        int size_long = longer.size();
        int size_short = shorter.size();
        int carry = 0;
        
        for(int i = 0; i < size_long; i++) {
            int longer_bit = longer[size_long - 1 - i] - '0';
            int shorter_bit = (i >= size_short) ? 0 : shorter[size_short - 1 - i] - '0';
            
            int add_bit = longer_bit + shorter_bit + carry;
            result = (char)('0' + (add_bit % 2))  + result;
            carry  = (add_bit > 1) ? 1 : 0;
        }
        
        if(carry != 0) result = '1' + result;
        
        
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}