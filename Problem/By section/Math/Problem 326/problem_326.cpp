#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(1)
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        int start = 0;
        int count = 0;
        int limit = INT_MAX / 3;
        while(true) {
            int result = n - start;
            if(result == 0) {
                return true;
            }else if(result < 0 || start > limit){
                return false;
            }else{
                start = pow(3, count);
            }
             count++;
        }
        
        return false;
        
        
        // return n > 0 && (1162261467 % n == 0);
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}