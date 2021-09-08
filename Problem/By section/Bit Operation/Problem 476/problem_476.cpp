#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // num = 10111      mask = 11111 
    // num ^ mask = 01000
    // Time: O(logn), Space: O(1)
    int findComplement(int num) {
        int num_bits = log2(num);
        long long mask = ((long long)1 << (num_bits + 1)) - 1; // 100000 - 1 = 11111
        
        return num ^ mask;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}