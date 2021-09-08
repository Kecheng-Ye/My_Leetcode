#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    int getSum(int a, int b) {
        // in case for overflow
        long mask = 0xFFFFFFFF;
        
        while (b != 0) {
            int answer = (a ^ b) & mask;
            int carry = ((a & b) & mask) << 1;
            a = answer;
            b = carry;
        }
         
        return a < INT_MAX ? a : ~(a ^ mask);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}