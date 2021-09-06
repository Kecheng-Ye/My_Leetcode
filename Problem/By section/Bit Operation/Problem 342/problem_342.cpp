#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(1), Space: O(1)
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}