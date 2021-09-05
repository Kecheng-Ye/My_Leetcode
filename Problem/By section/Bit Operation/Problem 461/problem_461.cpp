#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    // int hammingDistance(int x, int y) {
    //     int z = x ^ y;
    //     int cnt = 0;
    //     while(z != 0) {
    //         if ((z & 1) == 1) cnt++;
    //         z = z >> 1;
    //     }
    //     return cnt;
    // }
    
    // Time: O(logn), Space: O(1)
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        while (z != 0) {
            z &= (z - 1);
            cnt++;
        }
        return cnt;
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}