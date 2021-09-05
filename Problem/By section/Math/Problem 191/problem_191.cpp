#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n == 0) return 0;
        return n % 2 + hammingWeight(n / 2);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}