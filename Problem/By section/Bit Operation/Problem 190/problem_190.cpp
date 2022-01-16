#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    // uint32_t reverseBits(uint32_t n) {
    //     uint32_t ret = 0;
    //     int cnt = 32;
        
    //     while(cnt-- > 0) {
    //         ret <<= 1;
    //         ret |= (n & 1);
    //         n >>= 1;
    //     }
        
    //     return ret;
    // }
    

    // if we want to apply this function for multiple times
    // we can use a hash set to cache evey bytes reverse
    unordered_map<uint8_t, uint8_t> record;
    
    // Time: O(logn), Space: O(logn)
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        
        for(int i = 0; i < 4; i++) {
            ret <<= 8;
            ret |= (reverseBytes(n & 0xFF));
            n >>= 8;
        }
        
        return ret;
    }
    
    uint8_t reverseBytes(uint8_t input) {
        if(record.count(input)) {
            return record[input];
        }
        
        uint8_t ret = 0;
        uint8_t temp = input;
        
        for(int i = 0; i < 8; i++) {
            ret <<= 1;
            ret |= (temp & 1);
            temp >>= 1;
        }
        
        record[input] = ret;
        return ret;
    }
    
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}