#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Time: O(logn), Space: O(logn)
    double myPow(double x, int n) {
        long long N = n; // prevent overflow
        if(n < 0) {
            N = -N;
            x = 1/x;
        }
        
        return power_helper(x, n);
    }
    
    // x^(2n) = x^n * x^n
    double power_helper(double x, long long n) {
        if(n == 0) return 1;
        
        double half = power_helper(x, n/2);
        
        if(n % 2 == 0) {
            return half * half;
        }else{
            return half * half * x;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}