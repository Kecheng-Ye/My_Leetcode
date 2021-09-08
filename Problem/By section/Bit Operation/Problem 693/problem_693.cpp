#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //      10101010101
    //  +    1010101010    ( number >> 1 )
    //  ---------------
    //  =   11111111111
    //  &  100000000000
    //  ---------------
    //  =             0    ( power of two )
    // Time: O(1), Space: O(1)
    bool hasAlternatingBits(int n) {
        long long result = n ^ (n >> 1);
        
        return (result & (result + 1)) == 0;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}