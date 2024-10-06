#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     // Time: O(logn), Space: O(logn)
//     double myPow(double x, int n) {
//         long long N = n; // prevent overflow
//         if(n < 0) {
//             N = -N;
//             x = 1/x;
//         }
        
//         return power_helper(x, n);
//     }
    
//     // x^(2n) = x^n * x^n
//     double power_helper(double x, long long n) {
//         if(n == 0) return 1;
        
//         double half = power_helper(x, n/2);
        
//         if(n % 2 == 0) {
//             return half * half;
//         }else{
//             return half * half * x;
//         }
//     }
// };

class Solution {
public:
    // Time: O(logn), Space: O(1)
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            return binaryExp(1 / x, -1 * n);
        }

        // Perform Binary Exponentiation.
        double result = 1;
        while (n) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n % 2 == 1) {
                result = result * x;
                n -= 1;
            }
            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x = x * x;
            n = n / 2;
        }
        return result;
    }

    double myPow(double x, int n) { return binaryExp(x, (long long)n); }
};

int main(int argc, char** argv) {
    Solution s;
    
    return 0;
}