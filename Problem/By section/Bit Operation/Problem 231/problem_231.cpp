#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        return (n & (n - 1)) == 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}